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
        acceptance corpus-acceptance crate-vendor crate-build crate-test crate-publish

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

test: $(BIN)
	@echo "Building tests..."
	$(CC) $(CFLAGS) -I$(RUNTIME) -I$(CSRC) $(SHARED_SRCS) $(CSRC)/slop_test.c $(LDFLAGS) -o $(BIN)/howl-test
	@echo "Running tests..."
	$(BIN)/howl-test

clean:
	rm -rf $(BIN) dist

release: CFLAGS = -O3 -Wall -Werror=switch -Wno-unused-function -Wno-unused-variable \
                  -Wno-return-type -Wno-pointer-sign -DNDEBUG \
                  -DSLOP_ARENA_NO_CAP \
                  -DSLOP_INTERN_THREADSAFE \
                  -DSLOP_INTERN_BUCKET_COUNT=65536 \
                  -DHOWL_VERSION=\"$(HOWL_VERSION)\"
release: clean cli
	@echo "Release binary built: $(BIN)/howl"

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
	check corpus/fixtures/hazards/unsatisfiable-consistent.ttl 1; \
	check corpus/fixtures/hazards/cyclic-hierarchy.ttl 0; \
	check corpus/fixtures/hazards/range-complex-fillers.ttl 0; \
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
# to prevent. GO is excluded until saturation is indexed (M1).
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
	echo "  skip go-2026-07-26 (saturation is unindexed until M1)"; \
	if [ "$$fail" -eq 0 ]; then echo "  real-corpus acceptance met"; \
	else echo "  CORPUS ACCEPTANCE FAILED"; exit 1; fi

# Fetch and SHA-256-verify the pinned external ontologies (corpus/MANIFEST.toml).
# Not committed: GO alone is 129 MB, and their licences differ from HOWL's.
corpus:
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
	python3 corpus/project.py --verify

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
