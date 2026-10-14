"""The profile ladder as the harnesses see it (SPEC.md §5, §5.1).

One list, so wiring a rung in is one edit here rather than one per harness.
"""

# Every rung a report may name, in §5.1's tie-break order. `horn-sriq` was
# dropped from the ladder (§5, 2026-10-08); HOWL refuses it, so no report
# ever names it.
RUNGS = ("el", "el++", "sriq")

# The rungs the engine runs today, and so the only ones a harness accepts.
# `sriq` joined when it was wired in (slice 11b, §12 M5).
BUILT = ("el", "el++", "sriq")


def expected():
    """The accepted --profile values, for an error message: "el, el++ or sriq"."""
    return ", ".join(BUILT[:-1]) + " or " + BUILT[-1]
