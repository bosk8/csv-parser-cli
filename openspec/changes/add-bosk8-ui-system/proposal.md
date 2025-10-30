## Why
The project currently ships a C++17 CSV parsing CLI without a production-ready UI/UX system. We need a reusable, accessible UI consistent with `style.md` (single source of truth) to enable a minimal, spec-driven web interface and component library for future tools while preserving the existing CLI.

## What Changes
- Add a Bosk8-compliant UI/UX system strictly derived from `style.md`.
- Introduce a minimal web UI for CSV filtering that mirrors CLI capabilities.
- Add an interactive component library (tokens, buttons, inputs, cards, grid, tooltip, FAQ/accordion) with states and accessibility.
- Add navigation/routing, IA, and user flows for importing CSV, filtering, and exporting results.
- Provide Style Compliance Matrix and Style Decisions Log (with derivations only from existing tokens).
- Provide dev handoff artifacts (CSS tokens map, redlines, examples) for immediate implementation.

## Impact
- Affected specs: `ui-system`, `components`, `csv-ui`.
- Affected code: Documentation and UI assets only; no changes to C++ sources.
- Non-breaking: CLI remains unchanged; web UI is additive.

## Constraints
- Absolute adherence to `style.md` tokens and patterns; no new tokens invented.
- All derived values must be documented with their source tokens and rules.
- Accessibility: WCAG 2.2 AA for contrast and keyboard flows.


