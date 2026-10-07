#!/bin/bash
# Regenerate transpiled C source in csrc/ from SLOP source.
#
# The committed C is what lets `make` build HOWL with nothing but a C
# compiler — no SLOP toolchain required. Regenerate it whenever SLOP
# source changes, and commit the result.
#
# Requires: SLOP toolchain (slop-compiler + the slop Python package)
#
# Usage: ./csrc/update_bootstrap.sh

set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_ROOT="$(cd "$SCRIPT_DIR/.." && pwd)"

echo "Generating transpiled C source..."
echo ""

# 1. Transpile the CLI — its entry point pulls in every library module.
echo "Pass 1: CLI (main + all dependencies)"
python3 "$SCRIPT_DIR/generate_c.py" --ffi-header "$PROJECT_ROOT/include/howl.h" "$PROJECT_ROOT/src" \
  "$PROJECT_ROOT/cli" "$SCRIPT_DIR/src"
echo ""

# 2. Transpile the test harness in append mode, which adds only the
#    test entry point — every shared module is already present from
#    pass 1 and is skipped rather than rewritten.
echo "Pass 2: Tests (append mode — adds test entry only)"
python3 "$SCRIPT_DIR/generate_c.py" --append "$PROJECT_ROOT/cli/tests" "$SCRIPT_DIR/src"
echo ""

# 3. Copy the runtime header.
echo "Copying runtime header..."
mkdir -p "$SCRIPT_DIR/runtime"
SLOP_RUNTIME="${SLOP_HOME}/src/slop/runtime/slop_runtime.h"
if [ ! -f "$SLOP_RUNTIME" ]; then
    echo "Error: Runtime header not found at $SLOP_RUNTIME"
    echo "       Is SLOP_HOME set correctly? (currently: ${SLOP_HOME:-unset})"
    exit 1
fi
cp "$SLOP_RUNTIME" "$SCRIPT_DIR/runtime/"
echo "  Copied $SLOP_RUNTIME -> $SCRIPT_DIR/runtime/"

echo ""
echo "Done. Files in $SCRIPT_DIR/src/:"
ls "$SCRIPT_DIR/src/"*.c 2>/dev/null | wc -l | tr -d ' '
echo " .c files"
