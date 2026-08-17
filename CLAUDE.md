## Development practices

### 1. Plan Mode Default
- Enter plan mode for any non-trivial task (3+ steps or architectural decisions).
- If something goes wrong, STOP and re-plan — don't press on.
- Write detailed specs upfront to reduce ambiguity.

### 2. Subagent Strategy
- Use subagents liberally to keep the main context clean; offload research, exploration, and
  parallel analysis. One focused task per subagent.

### 3. Self-improvement Loop
- After ANY correction from the user: record a typed `Lesson` in the graph (the source of
  truth) capturing the Pattern and a rule that prevents the same mistake. Recall-first
  (list-all) so you don't duplicate an existing Lesson. Optionally mirror to `tasks/lessons.md`.
- Review prior Lessons at session start via `get_relevant_context` / `query`.

### 4. Verification before Done
- Never mark a task complete without proving it works (tests, logs, demonstrated behavior).
- Ask: "Would a staff engineer approve this?"

### 5. Demand Elegance (Balanced)
- For non-trivial changes, pause and ask "is there a more elegant way." Skip for simple,
  obvious fixes — don't over-engineer. Challenge your own work before presenting it.

### 6. Autonomous Bug Fixing
- Given a bug report or failing tests: just fix it. Point at logs/errors, then resolve them —
  minimal context-switching for the user.

## Core Principles
- **Simplicity first** — make every change as simple as possible; touch minimal code.
- **No laziness** — find root causes, no temporary fixes; senior-developer standards.
- **Minimal impact** — change only what's necessary; avoid introducing bugs.

<!-- moosedev:begin — MOOSEDev project-memory workflow. Managed by `moosedev init`; edit around this block freely, or delete the whole begin…end block to opt out. -->
> This project uses the **MOOSEDev** MCP server for durable, structured, long-term memory.
> The typed **project knowledge graph is the source of truth** for architectural decisions,
> lessons, constraints, requirements, and patterns — **not** markdown files. Free-text notes
> (e.g. `tasks/lessons.md`, `tasks/todo.md`) are optional human-readable mirrors, never canonical.

## Working with project memory (MOOSEDev)

When the `moosedev` MCP tools are available, prefer them over re-deriving context from scratch.
The loop:

1. **Recall first.** Before non-trivial work, surface prior decisions/lessons/constraints from
   the graph — and show the queries you ran. "Recall first" means a **list-all**
   `get_relevant_context` (no `topic`), not only a topic probe: a topic-scoped empty result
   means nothing cleared the relevance floor, **not** that the graph is empty.
2. **Capture as typed records.** Record durable knowledge as you go with
   `record_important_decision` (pick the right `kind`). Capture the decision **and its
   rationale** (and the rejected alternative), not transient chatter. Always report what was
   written (kind / title / returned IRI) — no silent writes.
3. **Align before coining.** Run `align_concepts` (or `suggest_mappings`) before introducing a
   new term, so the graph doesn't drift.
4. **Correct, don't duplicate.** `supersede_decision` when there is a replacement;
   `retract_decision` to deprecate one without a successor. Never silently duplicate — recall
   (list-all) first to confirm a record is genuinely new.
5. **Validate.** Run `validate_against_architecture` after capturing; resolve violations.
6. **Approve a spec before implementing it** — when work starts on a spec ("implement X", "let's build
  X"), first check whether its `Requirement`s are in the graph. If they are not, extract the
  Requirements and Constraints the spec *states*, show them, and capture them as `accepted` records
  **before** the implementation decisions land — a decision captured first has no hub to be
  `isMotivatedBy`, and backfilling the edge later rarely happens. Being asked to implement a spec is
  **not** approval: show what would be written and get an explicit yes. Skip specs written *from* an
  existing decision cluster (they cite record IRIs, or say the graph wins on disagreement) — mining
  those duplicates the graph. In Claude Code the `approve-spec` skill runs this loop.

### Tool-selection ladder (cheap → precise)
- `get_relevant_context` — fast, deterministic, **shallow** lexical anchor/browse. Start here.
- `query` — walk-planned, synthesized natural-language answer **with a reasoning trace**. Use
  when you need reasoning over relationships, not just a label match. Keep questions short and
  focused (one question per call).
- `sparql` — exact, deterministic structural reads of the graph. Use for precise listings.

### Capture kinds
`ArchitecturalDecision` (the default — a choice + why + what was rejected) ·
`Constraint` (a hard limit/invariant) · `Requirement` (a goal/need) ·
`Pattern` (a deliberate recurring approach) · `AntiPattern` (something to avoid, + why) ·
`Lesson` (a non-obvious learning/gotcha).
<!-- moosedev:end -->
