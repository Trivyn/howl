# Human-readable spec

Two PDFs, both generated from markdown — regenerate rather than edit them.

| File | Source | Length |
|---|---|---|
| `howl-spec.pdf` | `../../SPEC.md` | full specification |
| `howl-brief.pdf` | `HOWL-brief.md` | condensed design summary |

`SPEC.md` at the repo root remains the source of truth. `HOWL-brief.md` is a
hand-written summary, not a mechanical extract, so it needs updating by hand when
the spec changes materially.

## Rebuild

    ./build.sh ../../SPEC.md   ./howl-spec.pdf  "HOWL" "…subtitle…"
    ./build.sh ./HOWL-brief.md ./howl-brief.pdf "HOWL — in brief" "…subtitle…" brief.css

## How it works

    markdown ──▶ prep.py ──▶ mmdc ──▶ pandoc ──▶ assemble.py ──▶ Chrome --print-to-pdf
               (pull out          (diagrams   (md → html)   (inline SVG
                mermaid)           → SVG)                    + stylesheets)

Chrome rather than LaTeX because the document is dense in description-logic notation
(`⊑ ⊓ ∃ ⊥ ≺ ⟹ …`) and the browser's font fallback covers it without per-glyph font
setup. It comes from puppeteer's bundled install, which `mmdc` already depends on.

`prep.py` also strips the in-document table of contents and flattens intra-document
anchor links, neither of which means anything on paper.

## Requirements

`pandoc`, `mmdc` (`@mermaid-js/mermaid-cli`), and a puppeteer Chrome under
`~/.cache/puppeteer`. `pdftoppm` is handy for eyeballing output but is not needed to build.

## Gotchas

- **Stylesheets are concatenated, not `@import`-ed.** The page is assembled in a temp
  directory, so a relative `@import` inside an inline `<style>` resolves against the
  wrong base and fails *silently* — taking every base rule with it while still
  producing a plausible-looking PDF.
- **Keep mermaid diagrams portrait.** A wide `flowchart LR` gets scaled to the column
  width and becomes illegible. Prefer `TB` and short node labels.
