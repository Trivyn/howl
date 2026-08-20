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
CFLAGS  ?= -O2 -Wall -Wno-unused-function -Wno-unused-variable \
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

.PHONY: all cli lib test clean release dist csrc slop-build verify corpus census \
        crate-vendor crate-build crate-test crate-publish

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

release: CFLAGS = -O3 -Wall -Wno-unused-function -Wno-unused-variable \
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

# Fetch and SHA-256-verify the pinned external ontologies (corpus/MANIFEST.toml).
# Not committed: GO alone is 129 MB, and their licences differ from HOWL's.
corpus:
	./corpus/fetch.sh

# Construct census against SPEC.md §5.2. Run over the committed fixtures it is a
# self-check on both: every v0/ fixture must gate clean, every out-of-profile/
# fixture must yield at least one omission.
census:
	python3 corpus/census.py corpus/fixtures/*/*.ttl

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
