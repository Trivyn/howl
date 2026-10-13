#!/bin/sh
# The Windows CLI as shipped (release.yml, ci.yml), run under MSYS2 after
# `make release`: its report is LF, the same bytes as on Linux and macOS
# (lf_stdout.c), and build/howl.exe imports only Windows' own DLLs, so it runs
# on a machine without MSYS2.
set -e
out=build/report-check.txt
./build/howl validate corpus/fixtures/v0/litmus.ttl --report > "$out"
grep -q '^howl-report ' "$out" || { echo "FAIL: no report from the litmus" >&2; exit 1; }
if grep -q "$(printf '\r')" "$out"; then
  echo "FAIL: the report has CRLF line endings" >&2; exit 1
fi
dlls=$(objdump -p build/howl.exe | sed -n 's/^[[:space:]]*DLL Name: //p')
echo "howl.exe imports: $dlls"
[ -n "$dlls" ] || { echo "FAIL: objdump listed no imports" >&2; exit 1; }
foreign=$(printf '%s\n' "$dlls" | grep -viE '^(kernel32|msvcrt|ucrtbase|advapi32|bcrypt|ntdll|user32|ws2_32)\.dll$|^api-ms-win-' || true)
[ -z "$foreign" ] || { echo "FAIL: howl.exe imports DLLs Windows does not ship: $foreign" >&2; exit 1; }
