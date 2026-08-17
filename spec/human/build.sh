#!/usr/bin/env bash
# Render a markdown spec to PDF with mermaid diagrams.
#
#   ./build.sh <input.md> <output.pdf> <title> <subtitle> [stylesheet]
#
# Chain: extract ```mermaid blocks -> mmdc renders each to SVG -> pandoc builds an
# HTML fragment -> the SVGs are substituted back -> headless Chrome prints to PDF.
# Chrome is used rather than LaTeX because the document is dense in DL notation
# (⊑ ⊓ ∃ ⊥ ≺ ⟹ …) and the browser's font fallback handles it without per-glyph setup.
set -euo pipefail

IN="$1"; OUT="$2"; TITLE="$3"; SUBTITLE="${4:-}"; CSS="${5:-page.css}"
HERE="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
WORK="$(mktemp -d)"
trap 'rm -rf "$WORK"' EXIT

CHROME="$(ls -d "$HOME"/.cache/puppeteer/chrome/*/chrome-mac-arm64/"Google Chrome for Testing.app" 2>/dev/null | tail -1)/Contents/MacOS/Google Chrome for Testing"
[ -x "$CHROME" ] || { echo "no chrome found" >&2; exit 1; }

# 1. pull the mermaid blocks out, leaving placeholders
python3 "$HERE/prep.py" "$IN" "$WORK"

# 2. render each diagram to SVG
shopt -s nullglob
for m in "$WORK"/diagram-*.mmd; do
  mmdc -i "$m" -o "${m%.mmd}.svg" -b transparent -c "$HERE/mermaid.json" >/dev/null 2>&1 \
    || echo "warn: mmdc failed on $(basename "$m")" >&2
done

# 3. markdown -> html fragment
pandoc "$WORK/body.md" -f gfm -t html5 --wrap=none -o "$WORK/body.html"

# 4. assemble the page, inlining the SVGs
CSSARGS=("$HERE/page.css"); [ "$CSS" != "page.css" ] && CSSARGS+=("$HERE/$CSS")
python3 "$HERE/assemble.py" "$WORK" "$TITLE" "$SUBTITLE" "${CSSARGS[@]}" > "$WORK/page.html"

# 5. print
"$CHROME" --headless --disable-gpu --no-pdf-header-footer \
  --print-to-pdf="$OUT" --virtual-time-budget=20000 \
  "file://$WORK/page.html" >/dev/null 2>&1

echo "$(basename "$OUT")  $(python3 -c "
import sys,re;d=open(sys.argv[1],'rb').read()
print(f'{len(d)/1024:.0f} KB, {len(re.findall(rb\"/Type\s*/Page[^s]\",d))} pages')" "$OUT")"
