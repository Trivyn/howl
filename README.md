# HOWL

**A consequence-based description-logic reasoner in SLOP — sibling to [GROWL](../growl).**

GROWL *materializes* an OWL 2 RL ontology (forward-chaining, edge enrichment). HOWL *classifies* a
description logic — it computes the complete subsumption hierarchy and consistency of a TBox,
including the defined-class subsumptions that RL materialization cannot see. The two compose through
RDF: HOWL classifies → emits inferred `subClassOf` → GROWL materializes/enriches.

- **GR-OWL / H-OWL** — the RL engine and the DL engine. "HOWL = **Horn OWL**" is apt: the first two
  targets (CB-EL++, Horn-SHIQ) are Horn fragments.
- **Status:** design draft. No implementation yet — see [`SPEC.md`](./SPEC.md).
- **When to build:** only when defined-class / existential-heavy ontologies enter scope
  (SPEC §13). Until then GROWL + its `--validate` smoke test suffices.

## Read next

[**`SPEC.md`**](./SPEC.md) — the full design: calculus choice, fragment roadmap (EL++ → Horn-SHIQ →
SROIQ), data model, verification story, GROWL relationship, milestones, and the "when is it actually
a DL reasoner?" threshold.
