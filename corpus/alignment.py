#!/usr/bin/env python3
"""M4 acceptance, independent subset differential, and pinned BFO/CCO benchmark.

python3 corpus/alignment.py test
python3 corpus/alignment.py oracle
python3 corpus/alignment.py bench

Only bench writes a tracked result (bench/results-alignment.json). Runtime files
and differential artifacts live under build/alignment. No input is rewritten.
"""
from __future__ import annotations

import hashlib
import json
import os
from pathlib import Path
import platform
import re
import statistics
import subprocess
import sys
import time
import unittest

ROOT = Path(__file__).resolve().parents[1]
HOWL = Path(os.environ.get("HOWL", ROOT / "build/howl")).resolve()
FIX = ROOT / "corpus/fixtures/alignment"
WORK = ROOT / "build/alignment"
SOURCE_FLAGS = ["--left-source", "urn:test:left", "--right-source", "urn:test:right", "--mapping-source", "urn:test:mappings"]
PREFIX = "@prefix : <urn:howl:alignment:test:> .\n@prefix owl: <http://www.w3.org/2002/07/owl#> .\n@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .\n"
SMALL_MAPS = [":A rdfs:subClassOf :X .", ":E rdfs:subClassOf :X .", ":X rdfs:subClassOf :D ."]
EXPECTED = [[2], [0, 1]]


def run(left=FIX / "fixed.ttl", right=FIX / "empty.ttl", mappings=FIX / "mappings.ttl", flags=(), repair=True, timeout=600):
    cmd = [str(HOWL), "align-check", str(left), str(right), str(mappings), "--report", *SOURCE_FLAGS]
    if repair:
        cmd.append("--repair")
    return subprocess.run([*cmd, *flags], capture_output=True, text=True, timeout=timeout)


def fields(text):
    result = {}
    for line in text.splitlines():
        k, _, v = line.partition(" ")
        result.setdefault(k, []).append(v)
    return result


def repairs(text):
    return [list(map(int, row.split())) for row in fields(text).get("repair", [])]


def file(name, text):
    WORK.mkdir(parents=True, exist_ok=True)
    path = WORK / name
    path.write_text(text)
    return path


class Acceptance(unittest.TestCase):
    def test_complete_family_all_profiles_and_workers(self):
        for profile in ("el", "el++", "sriq", "auto"):
            previous = None
            for workers in (1, 4):
                with self.subTest(profile=profile, workers=workers):
                    p = run(flags=("--profile", profile, "--workers", str(workers)))
                    self.assertEqual(p.returncode, 1, p.stderr + p.stdout)
                    self.assertEqual(repairs(p.stdout), EXPECTED)
                    self.assertEqual(fields(p.stdout)["search-complete"], ["true"])
                    if previous is not None:
                        self.assertEqual(p.stdout, previous)
                    previous = p.stdout

    def test_independent_powerset_reference(self):
        # Derive repairhood directly by classifying EVERY remaining theory.
        # This reference never computes conflicts or hitting sets.
        coherent = set()
        fixed = (FIX / "fixed.ttl").read_text()
        for mask in range(8):
            path = file(f"subset-{mask}.ttl", fixed + "\n" + PREFIX + "\n".join(m for i, m in enumerate(SMALL_MAPS) if not mask & (1 << i)))
            p = subprocess.run([str(HOWL), "validate", str(path), "--report"], capture_output=True, text=True, check=False)
            self.assertIn(p.returncode, (0, 1), p.stdout + p.stderr)
            if p.returncode == 0:
                coherent.add(mask)
        minimal = sorted(([i for i in range(3) if m & (1 << i)] for m in coherent if all(m ^ (1 << i) not in coherent for i in range(3) if m & (1 << i))), key=lambda r: (len(r), r))
        self.assertEqual(minimal, EXPECTED)
        self.assertEqual(repairs(run().stdout), minimal)

    def test_order_and_annotation_identity(self):
        annotated = PREFIX + "\n".join(reversed(SMALL_MAPS)) + '''
[] a owl:Axiom ; owl:annotatedSource :A ; owl:annotatedProperty rdfs:subClassOf ; owl:annotatedTarget :X ; rdfs:comment "first" .
[] a owl:Axiom ; owl:annotatedSource :A ; owl:annotatedProperty rdfs:subClassOf ; owl:annotatedTarget :X ; rdfs:comment "second" .
'''
        self.assertEqual(run().stdout, run(mappings=file("annotated.ttl", annotated)).stdout)

    def test_terminal_states(self):
        p = run(mappings=FIX / "empty.ttl")
        self.assertEqual(p.returncode, 0)
        self.assertIn("already-coherent true", p.stdout)
        self.assertEqual(repairs(p.stdout), [])
        fixed = file("unrepairable.ttl", (FIX / "fixed.ttl").read_text() + "\n:A rdfs:subClassOf owl:Nothing .\n")
        p = run(left=fixed)
        self.assertEqual(p.returncode, 1)
        self.assertIn("unrepairable-by-mappings true", p.stdout)
        self.assertEqual(repairs(p.stdout), [])

    def test_fixed_duplicate_cannot_be_removed(self):
        fixed = file("fixed-copy.ttl", (FIX / "fixed.ttl").read_text() + "\n:X rdfs:subClassOf :D .\n")
        p = run(left=fixed)
        self.assertEqual(repairs(p.stdout), [[0, 1]])
        self.assertIn("search-complete true", p.stdout)

    def test_separate_phase_budgets_and_unknown(self):
        for option in ("--conflict-calls", "--conflict-nodes", "--hitting-nodes"):
            with self.subTest(option=option):
                p = run(flags=(option, "0"))
                self.assertIn("search-complete false", p.stdout)
                self.assertTrue(all(r in EXPECTED for r in repairs(p.stdout)))
        p = run(flags=("--max-iterations", "0"))
        self.assertEqual(p.returncode, 2)
        self.assertIn("search-complete false", p.stdout)
        self.assertEqual(repairs(p.stdout), [])
        self.assertNotIn("already-coherent true", p.stdout)
        # Caps never make worker scheduling part of the result.
        for cap in (0, 1, 2, 3):
            self.assertEqual(run(flags=("--conflict-calls", str(cap), "--workers", "1")).stdout,
                             run(flags=("--conflict-calls", str(cap), "--workers", "4")).stdout)

    def test_check_only_and_invalid_flags(self):
        p = run(repair=False)
        self.assertEqual(p.returncode, 1)
        self.assertNotIn("howl-repair", p.stdout)
        for flags in (("--workers", "0"), ("--conflict-calls", "-1"), ("--conflict-calls", "4oops"), ("--max-iterations", "10001"), ("--left-source", "relative"), ("--unknown",)):
            with self.subTest(flags=flags):
                self.assertEqual(run(flags=flags).returncode, 3)


PINNED = [
    ("bfo-core-2024-02-07.ttl", "128f5fe1dab7ee804a3037a836813e5953c846eeeefee883a47d5db0b37a106b"),
    ("cco-2024-11-06.ttl", "e609db27478a2c8b52b9bb5eb5ac979ac323510e851c368e4d9ec7d1c153fe5b"),
]
BENCH_PREFIX = "@prefix bfo: <http://purl.obolibrary.org/obo/> .\n@prefix : <urn:howl:alignment:bench:> .\n@prefix owl: <http://www.w3.org/2002/07/owl#> .\n@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .\n"
BENCH_CORE = ["bfo:BFO_0000004 rdfs:subClassOf :X .", "bfo:BFO_0000020 rdfs:subClassOf :X .", ":X rdfs:subClassOf bfo:BFO_0000003 ."]
BENCH_DECLS = ":X a owl:Class .\n" + "\n".join(f":Benign{i:02} a owl:Class ." for i in range(29)) + "\n"
BENCH_BENIGN = "\n".join(f":Benign{i:02} rdfs:subClassOf owl:Thing ." for i in range(29)) + "\n"


def benchmark_input():
    paths = []
    for name, expected in PINNED:
        path = ROOT / "corpus/vendor" / name
        actual = hashlib.sha256(path.read_bytes()).hexdigest()
        if actual != expected:
            raise RuntimeError(f"{name}: expected {expected}, got {actual}")
        paths.append(path)
    mapping = file("benchmark-mappings.ttl", BENCH_PREFIX + BENCH_DECLS + BENCH_BENIGN + "\n".join(BENCH_CORE) + "\n")
    return *paths, mapping


def oracle(large=False):
    oracle_bin = ROOT / "oracle/build/oracle"
    destination = WORK / ("oracle-large" if large else "oracle-small")
    destination.mkdir(parents=True, exist_ok=True)
    if large:
        left, right, _ = benchmark_input()
        backgrounds = [left, right]
        prefix, decls, benign, core = BENCH_PREFIX, BENCH_DECLS, BENCH_BENIGN, BENCH_CORE
    else:
        backgrounds = [FIX / "fixed.ttl"]
        prefix, decls, benign, core = PREFIX, "", "", SMALL_MAPS
    files = []
    for mask in range(8):
        # OWL API loads each fixed document through its import closure,
        # independently parsing and scoping its blank nodes. No HOWL
        # decoder, projection, or repair code participates in the oracle.
        imports = ", ".join(f"<{p.resolve().as_uri()}>" for p in backgrounds)
        text = prefix + f"<urn:howl:oracle:subset:{mask}> a owl:Ontology ; owl:imports {imports} .\n"
        text += decls + benign + "\n".join(m for i, m in enumerate(core) if not mask & (1 << i))
        path = destination / f"subset-{mask}.ttl"
        path.write_text(text + "\n")
        files.append(path)
    out = destination / "reports"
    p = subprocess.run([str(oracle_bin), "report", "--reasoner", "hermit", "--out", str(out), *map(str, files)], capture_output=True, text=True, timeout=600)
    if p.returncode or p.stderr.strip() or "FAIL" in p.stdout:
        raise RuntimeError(p.stdout + p.stderr)
    coherent = set()
    for mask, path in enumerate(files):
        matches = list(out.glob(f"*{path.stem}.report"))
        if len(matches) != 1:
            raise RuntimeError(f"missing unique oracle report for {path}: {matches}")
        text = matches[0].read_text()
        if "inconsistent true" not in text and not any(line.startswith("unsat ") for line in text.splitlines()):
            coherent.add(mask)
    expected = {3, 4, 5, 6, 7}  # Remove both outer mappings, or the shared mapping.
    if coherent != expected:
        raise AssertionError(f"HermiT subset coherence {coherent} != {expected}")
    print(f"HermiT {'BFO/CCO' if large else 'fixture'}: all 8 subsets agree; exact repairs {{b}}, {{a,c}}")
    return {"reasoner": "HermiT", "subsets": 8, "coherent_removed_masks": sorted(coherent)}


def bench():
    left, right, mapping = benchmark_input()
    independent = oracle(large=True)
    results, canonical = [], None
    for index in range(4):
        start = time.monotonic()
        p = run(left, right, mapping, ("--profile", "sriq", "--workers", "4", "--timings"), timeout=900)
        elapsed = time.monotonic() - start
        f = fields(p.stdout)
        assert p.returncode == 1, p.stdout + p.stderr
        assert f["search-complete"] == ["true"], p.stdout
        assert f["mappings"] == ["32"], p.stdout
        refs = {int(row.split(" ", 1)[0]): row for row in f["mapping"]}
        actual = [[refs[i].split("> ", 1)[1] for i in r] for r in repairs(p.stdout)]
        shared = "SubClassOf(urn:howl:alignment:bench:X http://purl.obolibrary.org/obo/BFO_0000003)"
        outer = [f"SubClassOf(http://purl.obolibrary.org/obo/{c} urn:howl:alignment:bench:X)" for c in ("BFO_0000004", "BFO_0000020")]
        assert actual == [[shared], outer], actual
        if canonical is not None:
            assert canonical == p.stdout, "benchmark report changed between runs"
        canonical = p.stdout
        match = re.search(r"peak_mb=(\d+)", p.stderr)
        if not match:
            raise RuntimeError("missing alignment peak memory: " + p.stderr)
        sample = {"elapsed_seconds": round(elapsed, 3), "peak_mb": int(match[1]), "conflict_calls": int(f["conflict-calls"][0]), "verification_calls": int(f["verification-calls"][0])}
        print(f"{'warmup' if index == 0 else 'measured '+str(index)}: {sample}", flush=True)
        if index:
            results.append(sample)
    median = statistics.median(r["elapsed_seconds"] for r in results)
    passed = median <= 600 and all(r["peak_mb"] <= 8192 for r in results)
    record = {"protocol": "M4 full BFO/CCO, 32 mappings, W=4, explicit sriq, 1 warmup + 3 runs", "platform": platform.platform(), "sources": dict(PINNED), "mapping_sha256": hashlib.sha256(mapping.read_bytes()).hexdigest(), "binary_sha256": hashlib.sha256(HOWL.read_bytes()).hexdigest(), "report_sha256": hashlib.sha256(canonical.encode()).hexdigest(), "oracle": independent, "runs": results, "median_seconds": median, "threshold_seconds": 600, "threshold_peak_mb": 8192, "passed": passed}
    (ROOT / "bench/results-alignment.json").write_text(json.dumps(record, indent=2) + "\n")
    if not passed:
        raise AssertionError(f"M4 performance gate failed: {record}")
    print("M4 performance gate passed", flush=True)


if __name__ == "__main__":
    mode = sys.argv[1] if len(sys.argv) > 1 else "test"
    if mode == "test":
        unittest.main(argv=[sys.argv[0]], verbosity=2)
    elif mode == "oracle":
        oracle()
    elif mode == "bench":
        bench()
    else:
        raise SystemExit("usage: alignment.py test|oracle|bench")
