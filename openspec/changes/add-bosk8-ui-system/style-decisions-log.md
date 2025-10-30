## Style Decisions Log
Timestamp format: YYYY-MM-DD

2025-10-30
- Derivation: Input padding
  - Rule: Inputs use spacing from existing tokens. Derived from `--space-0_75` (vertical) and `--space-1` (horizontal) to maintain density in `style.md`.
- Derivation: Input radius
  - Rule: Use smallest radius `--r-sm` to match minimal radii guidance.
- Conflict: Need button default style
  - Resolution: Use `.copy-btn` pattern as base for buttons per `style.md` Links & Actions. No new token added.
- Constraint: Tooltip mobile interaction
  - Resolution: Use `.tooltip-trigger.active` as specified; toggle via JS class for mobile, hover for desktop.


