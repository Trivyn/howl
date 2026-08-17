"""Wrap the pandoc HTML fragment in a print stylesheet and inline the diagram SVGs."""
import os
import re
import sys

work, title, subtitle = sys.argv[1], sys.argv[2], sys.argv[3]
body = open(f"{work}/body.html").read()
# stylesheets are CONCATENATED, not @import-ed: the page lives in a temp dir, so a
# relative @import inside an inline <style> would resolve against the wrong base and
# fail silently — which it did, taking every base rule with it.
css = "\n".join(open(p).read() for p in sys.argv[4:])


def svg(m):
    idx = m.group(1)
    path = f"{work}/diagram-{idx}.svg"
    if not os.path.exists(path):
        return f'<p class="diagram-missing">[diagram {idx} failed to render]</p>'
    s = open(path).read()
    s = re.sub(r"<\?xml[^>]*\?>", "", s)
    # mmdc emits a fixed pixel width; let it scale to the column instead
    s = re.sub(r'(<svg[^>]*?)\swidth="[^"]*"', r"\1", s, count=1)
    s = re.sub(r'(<svg[^>]*?)\sheight="[^"]*"', r"\1", s, count=1)
    return f'<figure class="diagram">{s}</figure>'


# pandoc wraps the HTML comment in nothing, but may leave it bare or in a <p>
body = re.sub(r"(?:<p>)?<!--DIAGRAM-(\d+)-->(?:</p>)?", svg, body)

print(f"""<!doctype html>
<html><head><meta charset="utf-8"><title>{title}</title>
<style>{css}</style></head>
<body>
<header class="cover">
  <h1 class="cover-title">{title}</h1>
  <p class="cover-sub">{subtitle}</p>
</header>
{body}
</body></html>""")
