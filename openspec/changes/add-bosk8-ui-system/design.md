## Context
Add a Bosk8-compliant UI system while keeping the existing C++ CLI intact. The UI will be a minimal static web front-end (no framework required) that can be embedded later into other apps. Strictly adhere to `style.md`.

## Goals / Non-Goals
- Goals: Reusable tokens, global base, key components, CSV UI screens, accessibility.
- Non-Goals: Change C++ behavior, add back-end APIs, or invent new tokens.

## Decisions
- Use pure CSS variables as defined in `style.md` for tokens.
- Components are built from `.card`, `.grid-tiles`, `.tooltip`, `.faq-*`, `.link`, and text classes per `style.md`.
- All spacing/typography derived from `--fs-base`, `--space-*`, and the specified font stack.

## Risks / Trade-offs
- Minimal JS interactions: rely on CSS-hover for desktop and `.active` class for mobile (per tooltip pattern). Keeps complexity low.

## Migration Plan
- None required. UI is additive.

## Open Questions
- Should we add file drag-and-drop to the importer? If added, must map to existing spacing and borders.


