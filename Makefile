# HOWL — a consequence-based description-logic reasoner
# Build from transpiled C sources — no SLOP toolchain required.
#
#   make           build the CLI
#   make lib       build the static library
#   make test      build and run the test harness
#   make release   optimized CLI build
#   make slop-build   rebuild via the SLOP toolchain, refresh include/howl.h
#   make csrc      regenerate the committed C from SLOP source
#   make verify    run the Z3 contract checker

CC      ?= cc
# Version is sourced from slop.toml [project]; override with `make HOWL_VERSION=x.y.z`
HOWL_VERSION ?= $(shell sed -n 's/^version = "\(.*\)"/\1/p' slop.toml | head -1)
# -Werror=switch IS A CORRECTNESS GATE, NOT A STYLE FLAG. SPEC.md §5.2
# requires the disposition matrix to be "a total function over RawAxiom
# ... generated from it rather than maintained by hand", so that adding
# a construct cannot silently leave it undispositioned. SLOP's own
# checker only WARNS on a non-exhaustive match, but the transpiler
# emits SLOP_UNREACHABLE() after the switch rather than as a default
# arm, specifically so -Wswitch still fires (csrc/runtime:86-88). This
# promotes that to a hard build error naming the missing variant.
# Without it the failure surfaces as an abort() on a real ontology.
CFLAGS  ?= -O2 -Wall -Werror=switch -Wno-unused-function -Wno-unused-variable \
           -Wno-return-type -Wno-pointer-sign \
           -DSLOP_ARENA_NO_CAP \
           -DSLOP_INTERN_THREADSAFE \
           -DSLOP_INTERN_BUCKET_COUNT=65536 \
           -DHOWL_VERSION=\"$(HOWL_VERSION)\"
LDFLAGS ?= -lpthread
AR      ?= ar

CSRC    = csrc/src
RUNTIME = csrc/runtime
BIN     = build
OBJ     = $(BIN)/obj

# slop_main.c and slop_test.c each define main(), so they are excluded
# from the shared set and linked in only by their own target.
ALL_SRCS    := $(wildcard $(CSRC)/*.c)
SHARED_SRCS := $(filter-out $(CSRC)/slop_main.c $(CSRC)/slop_test.c, $(ALL_SRCS))
SHARED_OBJS := $(patsubst $(CSRC)/%.c,$(OBJ)/%.o,$(SHARED_SRCS))

.PHONY: all cli lib test clean release dist csrc slop-build verify corpus census project project-verify example \
        acceptance corpus-acceptance golden golden-update test-asan golden-asan crate-vendor crate-build crate-test crate-publish \
        oracle probes probes-update diff-fixtures conformance-fetch conformance conformance-update \
        materialize diff-corpus diff-corpus-update test-tsan determinism determinism-corpus bench bench-check

PLATFORM ?= unknown

all: cli

$(BIN):
	mkdir -p $(BIN)

$(OBJ):
	mkdir -p $(OBJ)

$(OBJ)/%.o: $(CSRC)/%.c | $(OBJ)
	$(CC) $(CFLAGS) -I$(RUNTIME) -I$(CSRC) -c $< -o $@

lib: $(BIN)/libhowl.a

$(BIN)/libhowl.a: $(SHARED_OBJS) | $(BIN)
	$(AR) rcs $@ $^
	@echo "  -> $@"

cli: $(BIN)
	@echo "Building howl..."
	$(CC) $(CFLAGS) -I$(RUNTIME) -I$(CSRC) $(SHARED_SRCS) $(CSRC)/slop_main.c $(LDFLAGS) -o $(BIN)/howl
	@echo "  -> $(BIN)/howl"

# NO CLOCK UNDER src/. HOWL never consults a clock inside a reasoning call
# (SPEC.md §6.8): a report must be a function of input and budget alone, and
# wall-clock timeouts belong to the host. Timings are the CLI's measurement.
test: $(BIN)
	@if grep -rnE 'now-ms|slop_now_ms|clock_gettime|gettimeofday|timespec_get|mach_absolute_time|\btime\(|\bclock\(' src/; then \
	  echo "FAIL: a clock read under src/ -- the engine never consults a clock (SPEC.md §6.8)"; exit 1; fi
	@echo "Building tests..."
	$(CC) $(CFLAGS) -I$(RUNTIME) -I$(CSRC) $(SHARED_SRCS) $(CSRC)/slop_test.c $(LDFLAGS) -o $(BIN)/howl-test
	@echo "Running tests..."
	$(BIN)/howl-test

# The test harness under AddressSanitizer. Saturation frees a scratch arena at
# every barrier, so anything a round allocates there and the store keeps is a
# use-after-free -- silent in an optimized build, a hard failure here.
test-asan: $(BIN)
	@echo "Building tests with AddressSanitizer..."
	$(CC) -O1 -g -fsanitize=address -fno-omit-frame-pointer -Wall -Werror=switch \
	  -Wno-unused-function -Wno-unused-variable -Wno-return-type -Wno-pointer-sign \
	  -DSLOP_ARENA_NO_CAP -DSLOP_INTERN_THREADSAFE -DSLOP_INTERN_BUCKET_COUNT=65536 \
	  -DHOWL_VERSION=\"$(HOWL_VERSION)\" -I$(RUNTIME) -I$(CSRC) \
	  $(SHARED_SRCS) $(CSRC)/slop_test.c $(LDFLAGS) -o $(BIN)/howl-test-asan
	ASAN_OPTIONS=detect_leaks=0 $(BIN)/howl-test-asan

# THE CLI UNDER ASan, OVER THE GOLDENS. HOWL frees arenas as each phase of a
# run ends, so a string or table left pointing into a freed arena is the
# failure to fear - and only a real run over real input reaches every such
# pointer; the unit tests do not. This builds the CLI under ASan and runs
# `golden` with it: every fixture, plus RO and OBI (GO and EL-GALEN are left
# out for time and memory; `golden` covers them without ASan). A memory error
# exits 99, which no verdict uses, so it can never match a golden.
golden-asan: $(BIN)
	$(CC) -O1 -g -fsanitize=address -fno-omit-frame-pointer -Wall -Werror=switch \
	  -Wno-unused-function -Wno-unused-variable -Wno-return-type -Wno-pointer-sign \
	  -DSLOP_ARENA_NO_CAP -DSLOP_INTERN_THREADSAFE -DSLOP_INTERN_BUCKET_COUNT=65536 \
	  -DHOWL_VERSION=\"$(HOWL_VERSION)\" -I$(RUNTIME) -I$(CSRC) \
	  $(SHARED_SRCS) $(CSRC)/slop_main.c $(LDFLAGS) -o $(BIN)/howl-asan
	ASAN_OPTIONS=detect_leaks=0:exitcode=99 $(MAKE) --no-print-directory golden \
	  HOWL=./$(BIN)/howl-asan GOLDEN_CORPUS="ro-2025-12-17 obi-2026-07-27"

# THE ROUND-JOIN RUNS ON WORKER THREADS (M1 slice 5), and ThreadSanitizer is
# what shows the join shares nothing mutable: workers read the frozen store
# and write only their own arena and RoundDelta. Every test goes through the
# parallel path (default-config's worker count is 4). TSan and ASan cannot
# share a binary, hence a target of its own; halt_on_error makes a race fail.
test-tsan: $(BIN)
	@echo "Building tests with ThreadSanitizer..."
	$(CC) -O1 -g -fsanitize=thread -Wall -Werror=switch \
	  -Wno-unused-function -Wno-unused-variable -Wno-return-type -Wno-pointer-sign \
	  -DSLOP_ARENA_NO_CAP -DSLOP_INTERN_THREADSAFE -DSLOP_INTERN_BUCKET_COUNT=65536 \
	  -DHOWL_VERSION=\"$(HOWL_VERSION)\" -I$(RUNTIME) -I$(CSRC) \
	  $(SHARED_SRCS) $(CSRC)/slop_test.c $(LDFLAGS) -o $(BIN)/howl-test-tsan
	TSAN_OPTIONS=halt_on_error=1 $(BIN)/howl-test-tsan

# M1 (e): the canonical report is byte-identical at W in {1,2,4,8} for every
# cap in {0, 1, R/2, R-1, R, unbounded}, and some cap must actually cut a run
# short. Fixtures here and in CI; the corpus locally (GO and EL-GALEN take
# ~20 s a run).
determinism: cli
	python3 corpus/determinism.py

determinism-corpus: cli
	python3 corpus/determinism.py --corpus

clean:
	rm -rf $(BIN) dist

RELEASE_CFLAGS = -O3 -Wall -Werror=switch -Wno-unused-function -Wno-unused-variable \
                 -Wno-return-type -Wno-pointer-sign -DNDEBUG \
                 -DSLOP_ARENA_NO_CAP \
                 -DSLOP_INTERN_THREADSAFE \
                 -DSLOP_INTERN_BUCKET_COUNT=65536 \
                 -DHOWL_VERSION=\"$(HOWL_VERSION)\"

release: CFLAGS = $(RELEASE_CFLAGS)
release: clean cli
	@echo "Release binary built: $(BIN)/howl"

# M1 (c), SPEC.md §12's benchmark protocol. Local only: a timing on CI
# hardware proves nothing about the machine the results name. Builds its own
# release binary under $(BIN)/bench so $(BIN)/howl is never replaced under a
# concurrent gate, then times every corpus entry against its routed oracle and
# writes bench/results.txt (commit it). Needs `make oracle` and `make materialize`.
bench: oracle
	@mkdir -p $(BIN)/bench
	$(CC) $(RELEASE_CFLAGS) -I$(RUNTIME) -I$(CSRC) $(SHARED_SRCS) $(CSRC)/slop_main.c $(LDFLAGS) -o $(BIN)/bench/howl
	HOWL=$(BIN)/bench/howl BENCH_CFLAGS='$(RELEASE_CFLAGS)' python3 bench/bench.py run

# Cheap: results.txt still names the certified reports, and its verdicts follow.
bench-check:
	python3 -m unittest bench/test_bench.py
	python3 bench/bench.py check

# --- SLOP toolchain targets (require slop on PATH) ---

slop-build:
	slop build
	@mkdir -p include
	cp build/howl.h include/howl.h
	@echo "  -> include/howl.h updated"

csrc:
	./csrc/update_bootstrap.sh

# Z3 weakest-precondition contract checking (§7). This is what licenses
# the "verified faithful to a proven calculus" claim — it proves the
# implementation cannot drift from the calculus without a contract
# failing. It does NOT prove soundness or completeness, which are
# model-theoretic and come from the published proofs plus differential
# testing.
verify:
	slop verify

# Executable @example blocks on the completion rules. These are real coverage
# as of slop 0.2.1 -- under 0.1.2 any example with a non-scalar argument was
# skipped AND counted as a pass, so a green line meant nothing.
example:
	slop test src/rules/el.slop
	slop test src/canon.slop
	slop test src/normalize.slop
	slop test src/decode.slop

# SPEC.md §12's acceptance criteria, as exit codes. These are the contract a
# consumer actually observes, and they are checked here rather than only
# in-process because the CLI is where the verdict becomes a number: a test
# asserting `verdict-inconclusive` still passes if the exit-code table drifts.
# 2 is deliberately NOT a pass.
acceptance: cli
	@rc=0; fail=0; \
	check() { ./$(BIN)/howl validate $$1 >/dev/null 2>&1; rc=$$?; \
	          if [ "$$rc" -eq "$$2" ]; then echo "  ok   $$1 -> $$rc"; \
	          else echo "  FAIL $$1 -> $$rc (expected $$2)"; fail=1; fi; }; \
	check corpus/fixtures/v0/litmus.ttl 0; \
	check corpus/fixtures/hazards/unattested-import.ttl 2; \
	check corpus/fixtures/hazards/abox-disjoint-range.ttl 1; \
	check corpus/fixtures/hazards/annotation-heavy.ttl 0; \
	check corpus/fixtures/hazards/declared-unused-class.ttl 0; \
	check corpus/fixtures/hazards/rbox-regularity-reject.ttl 2; \
	check corpus/fixtures/hazards/punning.ttl 0; \
	check corpus/fixtures/hazards/seed-only-entailment.ttl 0; \
	check corpus/fixtures/hazards/owl-nothing-present.ttl 0; \
	check corpus/fixtures/hazards/inconsistent-via-individual.ttl 1; \
	check corpus/fixtures/hazards/undeclared-individual.ttl 1; \
	check corpus/fixtures/hazards/anonymous-class-assertion.ttl 1; \
	check corpus/fixtures/hazards/annotated-annotation.ttl 0; \
	check corpus/fixtures/hazards/smaller-side-join.ttl 0; \
	check corpus/fixtures/hazards/undeclared-filler.ttl 2; \
	check corpus/fixtures/hazards/disjoint-repeated-member.ttl 1; \
	check corpus/fixtures/hazards/logical-triple-on-header-node.ttl 2; \
	check corpus/fixtures/hazards/unsatisfiable-consistent.ttl 1; \
	check corpus/fixtures/hazards/cyclic-hierarchy.ttl 0; \
	check corpus/fixtures/hazards/range-complex-fillers.ttl 0; \
	check corpus/fixtures/hazards/role-hierarchy-deep.ttl 0; \
	check corpus/fixtures/out-of-profile/inverse-expressions.ttl 2; \
	if [ "$$fail" -eq 0 ]; then echo "  all SPEC.md §12 acceptance criteria met"; \
	else echo "  ACCEPTANCE FAILED"; exit 1; fi

# M0 acceptance (a) asks for a REAL ontology, and every fixture above passed
# while the first two real ones failed: RO faulted on inverse property
# expressions, and OBI reported itself inconsistent through a collapsed range
# key. Both are released OBO ontologies that their own pipelines classify, so
# neither has an unsatisfiable class; both carry out-of-profile axioms, so the
# honest verdict is 2. A missing .ttl FAILS rather than skipping — a gate that
# passes because its input was absent is the false pass this project exists
# to prevent. GO joined when saturation got its premise index (M1 slice 1): its
# single omission is one owl:inverseOf, exactly what the census predicts.
corpus-acceptance: cli
	@fail=0; \
	check() { f=corpus/vendor/$$1.ttl; \
	          if [ ! -f "$$f" ]; then echo "  MISSING $$f (run ./corpus/fetch.sh $$2)"; fail=1; return; fi; \
	          out=$$(./$(BIN)/howl validate $$f 2>&1); rc=$$?; \
	          unsat=$$(printf '%s\n' "$$out" | sed -n 's/.* \([0-9][0-9]*\) unsatisfiable.*/\1/p' | head -1); \
	          if [ "$$rc" -eq "$$3" ] && [ "$$unsat" = "0" ]; then echo "  ok   $$1 -> $$rc, 0 unsatisfiable"; \
	          else echo "  FAIL $$1 -> $$rc, $${unsat:-?} unsatisfiable (expected $$3, 0)"; fail=1; fi; }; \
	check ro-2025-12-17 ro 2; \
	check obi-2026-07-27 obi 2; \
	check go-2026-07-26 go 2; \
	check el-galen-2011-04-12 el-galen 0; \
	projected() { f=corpus/vendor/$$1.v0.ttl; \
	          if [ ! -f "$$f" ]; then echo "  MISSING $$f (run make materialize)"; fail=1; return; fi; \
	          rep=$$(./$(BIN)/howl validate $$f --report 2>/dev/null); rc=$$?; \
	          om=$$(printf '%s\n' "$$rep" | sed -n 's/^omitted //p'); \
	          if [ "$$rc" -eq "$$2" ] && [ "$$om" = "0" ]; then echo "  ok   $$1.v0 -> $$rc, omitted 0"; \
	          else echo "  FAIL $$1.v0 -> $$rc, omitted $${om:-?} (expected $$2, 0)"; fail=1; fi; }; \
	projected ro-2025-12-17 0; \
	projected obi-2026-07-27 0; \
	projected go-2026-07-26 0; \
	projected el-galen-2011-04-12 0; \
	if [ "$$fail" -eq 0 ]; then echo "  real-corpus acceptance met"; \
	else echo "  CORPUS ACCEPTANCE FAILED"; exit 1; fi

# GOLDEN REPORTS gate every performance change. They were captured on the
# engine BEFORE any M1 performance work, so a faster engine that derives one
# subsumption fewer -- or needs one round more, which changes what a capped run
# can see -- fails here rather than in a differential run much later. Fixture
# reports are committed text, so a deliberate change is reviewed as a diff; RO
# and OBI are too large to commit and are pinned by hash. Each golden ends with
# the exit code. A missing input FAILS: a gate that passes because its input
# was absent is the false pass this project exists to prevent. That includes a
# FIXTURE that disappeared: the fixture list is a wildcard over what exists, so
# a deleted or renamed .ttl would simply drop out of it, and `golden` therefore
# also walks the committed reports and fails on any whose source is gone.
# `golden-update` is for deliberate changes only.
GOLDEN_FIXTURES := $(wildcard corpus/fixtures/v0/*.ttl corpus/fixtures/hazards/*.ttl corpus/fixtures/out-of-profile/*.ttl \
                              corpus/fixtures/probes/*.ttl)
# IMPORT RUNS, `howl validate DOC.ttl -I IMPORT.ttl --report`, one per
# DOC:IMPORT pair in corpus/fixtures/imports/. They pin the CLI's merge of
# an attested import - its blank nodes standardized apart from the root's -
# which no single-file golden reaches.
GOLDEN_IMPORTS  := root:imported
# GO's golden was captured AFTER the premise index -- the unindexed engine never
# finished it -- so it pins stability, not correctness, until the S4 differential
# against ELK checks it.
GOLDEN_CORPUS   := ro-2025-12-17 obi-2026-07-27 go-2026-07-26 el-galen-2011-04-12
# Override to capture from a different build, e.g. the pre-change binary.
HOWL ?= ./$(BIN)/howl

# A golden must BE a report. The first capture passed `--report` before the
# input file, the CLI refused it, and every golden recorded that usage error --
# a gate both the old and new engine would pass forever. So a capture or a
# comparison whose output does not start with the report header fails outright.
golden: cli
	@fail=0; \
	for g in corpus/goldens/fixtures/*.report; do \
	  n=$$(basename $$g .report); src=""; \
	  for d in out-of-profile hazards v0 probes; do \
	    case "$$n" in "$$d"-*) src=corpus/fixtures/$$d/$${n#$$d-}.ttl; break;; esac; \
	  done; \
	  if [ -z "$$src" ] || [ ! -f "$$src" ]; then echo "  ORPHAN $$g (no source fixture $${src:-?})"; fail=1; fi; \
	done; \
	for f in $(GOLDEN_FIXTURES); do \
	  g=corpus/goldens/fixtures/$$(basename $$(dirname $$f))-$$(basename $$f .ttl).report; \
	  if [ ! -f "$$g" ]; then echo "  MISSING $$g"; fail=1; continue; fi; \
	  out=$$({ $(HOWL) validate $$f --report 2>/dev/null; echo "exit $$?"; }); \
	  case "$$out" in "howl-report 1"*) ;; *) echo "  NOT A REPORT $$f"; fail=1; continue;; esac; \
	  if [ "$$out" != "$$(cat $$g)" ]; then echo "  FAIL $$f differs from $$g"; fail=1; fi; \
	done; \
	for pair in $(GOLDEN_IMPORTS); do \
	  d=$${pair%%:*}; i=$${pair#*:}; g=corpus/goldens/imports/$$d.report; \
	  if [ ! -f "$$g" ]; then echo "  MISSING $$g"; fail=1; continue; fi; \
	  out=$$({ $(HOWL) validate corpus/fixtures/imports/$$d.ttl -I corpus/fixtures/imports/$$i.ttl --report 2>/dev/null; echo "exit $$?"; }); \
	  if [ "$$out" != "$$(cat $$g)" ]; then echo "  FAIL imports $$d -I $$i differs from $$g"; fail=1; fi; \
	done; \
	for c in $(GOLDEN_CORPUS); do \
	  f=corpus/vendor/$$c.ttl; g=corpus/goldens/$$c.sha256; \
	  if [ ! -f "$$f" ]; then echo "  MISSING $$f (run ./corpus/fetch.sh)"; fail=1; continue; fi; \
	  out=$$({ $(HOWL) validate $$f --report 2>/dev/null; echo "exit $$?"; }); \
	  case "$$out" in "howl-report 1"*) ;; *) echo "  NOT A REPORT $$f"; fail=1; continue;; esac; \
	  h=$$(printf '%s\n' "$$out" | shasum -a 256 | cut -d' ' -f1); \
	  if [ "$$h" = "$$(cat $$g)" ]; then echo "  ok   $$c"; else echo "  FAIL $$c report hash $$h"; fail=1; fi; \
	done; \
	if [ "$$fail" -eq 0 ]; then echo "  goldens unchanged"; else echo "  GOLDEN MISMATCH"; exit 1; fi

golden-update: cli
	@mkdir -p corpus/goldens/fixtures
	@fail=0; \
	for f in $(GOLDEN_FIXTURES); do \
	  g=corpus/goldens/fixtures/$$(basename $$(dirname $$f))-$$(basename $$f .ttl).report; \
	  out=$$({ $(HOWL) validate $$f --report 2>/dev/null; echo "exit $$?"; }); \
	  case "$$out" in "howl-report 1"*) printf '%s\n' "$$out" > $$g;; \
	    *) echo "  NOT A REPORT $$f -- golden not written"; fail=1;; esac; \
	done; \
	mkdir -p corpus/goldens/imports; \
	for pair in $(GOLDEN_IMPORTS); do \
	  d=$${pair%%:*}; i=$${pair#*:}; \
	  out=$$({ $(HOWL) validate corpus/fixtures/imports/$$d.ttl -I corpus/fixtures/imports/$$i.ttl --report 2>/dev/null; echo "exit $$?"; }); \
	  case "$$out" in "howl-report 1"*) printf '%s\n' "$$out" > corpus/goldens/imports/$$d.report;; \
	    *) echo "  NOT A REPORT imports $$d -- golden not written"; fail=1;; esac; \
	done; \
	for c in $(GOLDEN_CORPUS); do \
	  f=corpus/vendor/$$c.ttl; \
	  if [ ! -f "$$f" ]; then echo "  skip $$c (no $$f)"; continue; fi; \
	  out=$$({ $(HOWL) validate $$f --report 2>/dev/null; echo "exit $$?"; }); \
	  case "$$out" in "howl-report 1"*) \
	    printf '%s\n' "$$out" | shasum -a 256 | cut -d' ' -f1 > corpus/goldens/$$c.sha256; \
	    echo "  -> corpus/goldens/$$c.sha256";; \
	    *) echo "  NOT A REPORT $$f -- golden not written"; fail=1;; esac; \
	done; \
	[ "$$fail" -eq 0 ]

# THE DIFFERENTIAL (SPEC.md §10 item 1, M1 acceptance (b)). `oracle` builds the
# pinned ELK/HermiT program (oracle/, Gradle; the wrapper provisions a pinned
# JDK). `probes` runs the capability battery and fails if HOWL or HermiT misses
# a probe, or if an oracle's recorded capabilities (corpus/oracle-capabilities.txt)
# changed; `probes-update` rewrites that file, for a deliberate oracle change
# only. `diff-fixtures` compares HOWL with HermiT on every fixture it reasons
# over completely, and with ELK where the probes prove ELK capable. None of
# these joins `all` or `acceptance`: they need a JVM and the network once.
oracle:
	cd oracle && ./gradlew --quiet assemble

probes: cli oracle
	python3 corpus/differential.py probes

probes-update: cli oracle
	python3 corpus/differential.py probes --update

# The comparator's self-tests run first: a clean diff is evidence only from a
# comparator known to speak up when the two sides differ.
diff-fixtures: cli oracle
	python3 -m unittest -q corpus/test_entdiff.py
	python3 corpus/differential.py fixtures

# EXTERNAL CONFORMANCE: expected answers nobody on this project wrote — the
# W3C OWL 2 conformance suite's approved EL (in)consistency tests, and ELK's
# classification tests with their expected taxonomies (corpus/conformance.py).
# Sources are pinned by commit and sha256 in corpus/conformance.sha256 and
# fetched, never committed. Each test's outcome is recorded in
# corpus/conformance-status.txt; `conformance` fails on any mismatch or on a
# changed record, and `conformance-update` refuses to record while one fails.
conformance-fetch:
	python3 corpus/conformance.py fetch

conformance: cli oracle
	python3 -m unittest -q corpus/test_conformance.py
	python3 corpus/conformance.py run

conformance-update: cli oracle
	python3 corpus/conformance.py run --update

# THE CORPUS DIFFERENTIAL (M1 acceptance (b)): each materialized projection,
# HOWL against its ROUTED oracle — ELK for GO and EL-GALEN, HermiT for the
# range-bearing RO and OBI — recorded in corpus/corpus-differential.txt. Local
# only, like project-verify: the corpus is 135 MB with mixed licences.
diff-corpus: cli oracle
	python3 corpus/differential.py corpus

diff-corpus-update: cli oracle
	python3 corpus/differential.py corpus --update

# Fetch and SHA-256-verify the pinned external ontologies (corpus/MANIFEST.toml).
# Not committed: GO alone is 129 MB, and their licences differ from HOWL's.
corpus: oracle
	./corpus/fetch.sh

# Construct census against SPEC.md §5.2. Run over the committed fixtures it is a
# self-check on both: every v0/ fixture must gate clean, every out-of-profile/
# fixture must yield at least one omission.
census:
	python3 corpus/census.py corpus/fixtures/*/*.ttl

# Regenerate the pinned v0 projections as removal lists (corpus/projections/).
# `make project-verify` re-derives them and fails on drift, which is what CI
# should run -- a projection that silently changes invalidates every benchmark
# number and every differential diff taken against it.
project: corpus
	python3 corpus/project.py

project-verify:
	python3 -m unittest -q corpus/test_project.py
	python3 corpus/project.py --verify

# THE PROJECTED ONTOLOGIES ITSELF, as Turtle under corpus/vendor/ (not
# committed): the one input HOWL and the oracles share in the corpus
# differential. Pinned by content — re-parsed, ground hash and blank-node count
# against the .removals header, census 0 out-of-profile — not by bytes.
materialize: corpus
	python3 -m unittest -q corpus/test_project.py
	python3 corpus/project.py --materialize

dist:
	rm -rf dist
	mkdir -p dist/include dist/lib
	cp include/howl.h dist/include/
	cp csrc/runtime/slop_runtime.h dist/include/
	cp $(BIN)/libhowl.a dist/lib/
	cd dist && zip -r ../libhowl-$(PLATFORM).zip include/ lib/
	@echo "  -> libhowl-$(PLATFORM).zip"

# --- Rust crate targets ---

# These modules are provided by slop-std-sys / slop-rdf-sys. The Rust
# crate must not vendor its own copy, or consumers linking both will
# collide on duplicate symbols.
SHARED_MODULES := common file index list rdf serialize_ttl strlib thread ttl vocab xsd

CRATE_ALL_C := $(wildcard $(CSRC)/*.c)
CRATE_ALL_H := $(wildcard $(CSRC)/*.h)
CRATE_SRCS  := $(filter-out $(foreach m,$(SHARED_MODULES),$(CSRC)/slop_$(m).c),$(CRATE_ALL_C))
CRATE_HDRS  := $(filter-out $(foreach m,$(SHARED_MODULES),$(CSRC)/slop_$(m).h),$(CRATE_ALL_H))

crate-vendor:
	@mkdir -p rust/csrc/src rust/csrc/runtime
	rm -f $(foreach m,$(SHARED_MODULES),rust/csrc/src/slop_$(m).c rust/csrc/src/slop_$(m).h)
	cp $(CRATE_SRCS) $(CRATE_HDRS) rust/csrc/src/
	cp csrc/runtime/slop_runtime.h rust/csrc/runtime/
	cp LICENSE rust/LICENSE 2>/dev/null || true
	@echo "  -> rust/csrc/ vendored (shared modules excluded)"

crate-build: crate-vendor
	cd rust && cargo build

crate-test: crate-vendor
	cd rust && cargo test

crate-publish: crate-vendor
	cd rust && cargo publish --allow-dirty
