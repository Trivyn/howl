"""Extract ```mermaid blocks into .mmd files, leaving placeholders in the markdown.

Also strips the in-document table of contents (the PDF gets its own) and rewrites
intra-document anchor links to plain text, since they mean nothing on paper.
"""
import re
import sys

src, work = sys.argv[1], sys.argv[2]
s = open(src).read()

# drop the markdown TOC block — the PDF outline replaces it
s = re.sub(r"\n## Table of contents\n.*?\n---\n", "\n", s, flags=re.S)

# ```mermaid ... ``` -> placeholder
n = 0
out = []
for block in re.split(r"(?ms)^```mermaid\n(.*?)^```$", s):
    if n % 2:
        idx = n // 2
        open(f"{work}/diagram-{idx}.mmd", "w").write(block)
        out.append(f"\n<!--DIAGRAM-{idx}-->\n")
    else:
        out.append(block)
    n += 1
s = "".join(out)

# [text](#anchor) -> text  (paper has no anchors)
s = re.sub(r"\[([^\]]+)\]\(#[^)]*\)", r"\1", s)

open(f"{work}/body.md", "w").write(s)
print(f"{n // 2} diagrams", file=sys.stderr)
