"""Self-tests for bench/bench.py.

    python3 -m unittest bench/test_bench.py

Each case is a way a benchmark could report a number that does not measure
what the protocol says: a timing of a different or incomplete answer, a
warm-up counted as a measured run, a ratio or verdict that does not follow
from the medians, a result file gone stale against the certified record.
"""
import hashlib
import importlib.util
import io
import os
import re
import sys
import unittest
from contextlib import redirect_stdout

# Loaded by path: under `python3 -m unittest bench/test_bench.py` the name
# `bench` is this directory's package, not bench.py.
_spec = importlib.util.spec_from_file_location(
    "bench_harness", os.path.join(os.path.dirname(os.path.abspath(__file__)), "bench.py"))
bench = importlib.util.module_from_spec(_spec)
_spec.loader.exec_module(bench)

REPORT = b"howl-report 2\nprofile el\nverdict coherent\ntermination fixpoint\nrounds 3\ninconsistent false\n" \
         b"omitted 0\nunsatisfiable 0\nsubsumptions 1\nsub http://x/A http://x/A\n"
PIN = hashlib.sha256(REPORT).hexdigest()[:16]
ENT = "ab" * 32


def oracle_out(entailments=ENT, measured=bench.RUNS, warmup=bench.WARMUP):
    lines = ["bench-oracle reasoner elk 0.6.0 owlapi 5.1.20 jvm 21 workers 4 heap_mb 32768"]
    for i in range(warmup + measured):
        kind = "warmup" if i < warmup else "measured"
        # The warm-up is slow on purpose: counting it would move the median.
        slow = 1000.0 if kind == "warmup" else 0.0
        lines.append(f"bench run={i} {kind} parse_ms=500.000 create_ms={4 + slow:.3f} consistent_ms=70.000 "
                     f"classify_ms={180 + i:.3f} extract_ms=300.000 lines=10 entailments={entailments}")
    return "\n".join(lines) + "\n"


def runs(classify, n=bench.RUNS):
    return [{"classify": classify, "decode": classify / 4, "reason": classify / 2, "e2e": classify * 2,
             "peak": 2**30}] * n


RECORD = {"el-galen-2011-04-12": {"oracle": "elk", "howl-report": PIN, "oracle-entailments": ENT[:16]},
          "ro-2025-12-17": {"oracle": "hermit", "howl-report": PIN, "oracle-entailments": ENT[:16]}}


class Record(unittest.TestCase):
    def test_parses_the_differential_record(self):
        text = ("# comment\ngo-2026-07-26 source=653c ground=6d08 bnodes=a32a howl-report=5000 oracle=elk "
                "oracle-entailments=7075 subsumptions=459329 result=clean\n")
        rec = bench.parse_record(text)
        self.assertEqual(rec["go-2026-07-26"]["oracle"], "elk")
        self.assertEqual(rec["go-2026-07-26"]["howl-report"], "5000")


class HowlSide(unittest.TestCase):
    def test_the_certified_complete_report_passes(self):
        self.assertEqual(bench.check_report(REPORT, PIN), [])

    def test_a_different_answer_is_refused(self):
        other = REPORT.replace(b"subsumptions 1", b"subsumptions 2")
        self.assertTrue(any("not the certified" in e for e in bench.check_report(other, PIN)))

    def test_a_capped_run_is_refused_even_if_it_matched(self):
        capped = REPORT.replace(b"termination fixpoint", b"termination resource-limit")
        errors = bench.check_report(capped, hashlib.sha256(capped).hexdigest()[:16])
        self.assertTrue(any("fixpoint" in e for e in errors))

    def test_a_nonempty_omission_is_refused_even_if_it_matched(self):
        partial = REPORT.replace(b"omitted 0", b"omitted 3")
        errors = bench.check_report(partial, hashlib.sha256(partial).hexdigest()[:16])
        self.assertTrue(any("omitted" in e for e in errors))

    def test_timings_line(self):
        t = bench.parse_timing("noise\ntiming parse_ms=10 decode_ms=5 prepare_ms=20 reason_ms=30 total_ms=65\n")
        self.assertEqual(t, {"parse": 10, "decode": 5, "prepare": 20, "reason": 30, "total": 65})
        with self.assertRaises(bench.Refusal):
            bench.parse_timing("no timings here")
        # A line without decode_ms is the old boundary (decode inside prepare_ms): refused, not misread.
        with self.assertRaises(bench.Refusal):
            bench.parse_timing("timing parse_ms=10 prepare_ms=20 reason_ms=30 total_ms=60\n")


class OracleSide(unittest.TestCase):
    def test_warmup_is_not_measured_and_classify_is_create_consistent_classify(self):
        header, rs = bench.parse_oracle(oracle_out(), ENT[:16])
        self.assertIn("elk 0.6.0", header)
        self.assertEqual(len(rs), bench.RUNS)
        self.assertEqual(rs[0]["classify"], 4 + 70 + 181)
        self.assertEqual(rs[0]["e2e"], 500 + 4 + 70 + 181 + 300)

    def test_a_different_answer_is_refused(self):
        with self.assertRaises(bench.Refusal):
            bench.parse_oracle(oracle_out(entailments="cd" * 32), ENT[:16])

    def test_a_different_answer_in_the_warmup_is_refused_too(self):
        out = oracle_out().splitlines()
        out[1] = out[1].replace(ENT, "cd" * 32)
        with self.assertRaises(bench.Refusal):
            bench.parse_oracle("\n".join(out), ENT[:16])

    def test_a_failed_file_is_refused(self):
        with self.assertRaises(bench.Refusal):
            bench.parse_oracle(oracle_out() + "FAIL x.ttl: 1 warning(s)\n", ENT[:16])

    def test_a_missing_run_is_refused(self):
        with self.assertRaises(bench.Refusal):
            bench.parse_oracle(oracle_out(measured=bench.RUNS - 1), ENT[:16])

    def test_a_missing_warmup_is_refused(self):
        with self.assertRaises(bench.Refusal):
            bench.parse_oracle(oracle_out(warmup=0, measured=bench.RUNS + bench.WARMUP), ENT[:16])

    def test_a_duplicated_run_is_refused(self):
        lines = oracle_out().splitlines()
        lines[3] = lines[3].replace("run=2 ", "run=1 ")
        with self.assertRaises(bench.Refusal):
            bench.parse_oracle("\n".join(lines), ENT[:16])

    def test_a_missing_header_is_refused(self):
        with self.assertRaises(bench.Refusal):
            bench.parse_oracle(oracle_out().split("\n", 1)[1], ENT[:16])


class Verdicts(unittest.TestCase):
    def test_threshold_is_inclusive_and_elk_only(self):
        self.assertEqual(bench.verdict("elk", 5.0), "pass")
        self.assertEqual(bench.verdict("elk", 5.01), "FAIL")
        self.assertEqual(bench.verdict("hermit", 50.0), "reported")

    def test_entry_line_round_trips_and_checks_clean(self):
        lines = [bench.entry_line(s, r, runs(900.0), runs(200.0)) for s, r in RECORD.items()]
        self.assertEqual(bench.check_results(lines, RECORD), [])
        stem, f = bench.parse_entry(lines[0])
        self.assertEqual((f["ratio"], f["verdict"]), ("4.50", "pass"))

    def test_a_result_from_the_old_boundary_is_stale(self):
        # Before M1 slice 6b, decode was inside the window and no howl_decode_ms was written.
        lines = [bench.entry_line(s, r, runs(900.0), runs(200.0)) for s, r in RECORD.items()]
        old = [re.sub(r" howl_decode_ms=\S+", "", l) for l in lines]
        errors = bench.check_results(old, RECORD)
        self.assertEqual(len(errors), len(RECORD))
        self.assertTrue(all("howl_decode_ms" in e for e in errors))

    def test_just_over_the_threshold_fails_however_it_prints(self):
        # 1006 / 201 = 5.005: prints as 5.00 or 5.0, and is still over 5x.
        line = bench.entry_line("el-galen-2011-04-12", RECORD["el-galen-2011-04-12"], runs(1006.0), runs(201.0))
        self.assertIn("ratio=5.00", line)
        self.assertIn("verdict=FAIL", line)
        self.assertEqual(bench.check_results([line, self._ro()], RECORD), [])
        forged = line.replace("verdict=FAIL", "verdict=pass")
        self.assertTrue(any("verdict pass" in e for e in bench.check_results([forged, self._ro()], RECORD)))

    def _ro(self):
        return bench.entry_line("ro-2025-12-17", RECORD["ro-2025-12-17"], runs(1.0), runs(1.0))

    def test_median_not_mean(self):
        rs = runs(100.0, 4) + [{"classify": 10_000.0, "decode": 1, "reason": 1, "e2e": 1, "peak": 1}]
        self.assertEqual(bench.summarize(rs, "classify")[0], 100.0)

    def test_a_ratio_that_does_not_follow_is_caught(self):
        line = bench.entry_line("el-galen-2011-04-12", RECORD["el-galen-2011-04-12"], runs(900.0), runs(200.0))
        errors = bench.check_results([line.replace("ratio=4.50", "ratio=3.50"),
                                      bench.entry_line("ro-2025-12-17", RECORD["ro-2025-12-17"],
                                                       runs(1.0), runs(1.0))], RECORD)
        self.assertTrue(any("does not follow from the medians" in e for e in errors))

    def test_a_verdict_that_does_not_follow_is_caught(self):
        line = bench.entry_line("el-galen-2011-04-12", RECORD["el-galen-2011-04-12"], runs(2000.0), runs(200.0))
        self.assertIn("verdict=FAIL", line)
        errors = bench.check_results([line.replace("verdict=FAIL", "verdict=pass")], RECORD)
        self.assertTrue(any("verdict pass does not follow" in e for e in errors))

    def test_stale_pins_and_missing_entries_are_caught(self):
        stale = dict(RECORD, **{"el-galen-2011-04-12": dict(RECORD["el-galen-2011-04-12"], **{"howl-report": "0" * 16})})
        line = bench.entry_line("el-galen-2011-04-12", RECORD["el-galen-2011-04-12"], runs(900.0), runs(200.0))
        errors = bench.check_results([line], stale)
        self.assertTrue(any("stale" in e for e in errors))
        self.assertTrue(any("ro-2025-12-17: in the record but not benchmarked" in e for e in errors))

    def test_overall_status(self):
        passing = bench.entry_line("el-galen-2011-04-12", RECORD["el-galen-2011-04-12"], runs(900.0), runs(200.0))
        failing = bench.entry_line("el-galen-2011-04-12", RECORD["el-galen-2011-04-12"], runs(9000.0), runs(200.0))
        reported = bench.entry_line("ro-2025-12-17", RECORD["ro-2025-12-17"], runs(9000.0), runs(200.0))
        with redirect_stdout(io.StringIO()):
            self.assertEqual(bench.report([passing, reported]), 0)
            self.assertEqual(bench.report([failing, reported]), 1)
            self.assertEqual(bench.report([reported]), 1, "nothing gated means M1 (c) was not measured")


if __name__ == "__main__":
    unittest.main()
