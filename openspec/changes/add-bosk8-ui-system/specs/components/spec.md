## ADDED Requirements

### Requirement: Buttons
Buttons SHALL be minimal, borderless by default, using `.copy-btn` interaction patterns and adopting text/link styling from `style.md`.

#### Scenario: Default state
- **WHEN** button renders
- **THEN** it MUST use `display: inline-flex; align-items: center; gap: 0.75rem; background: transparent; border: none; cursor: pointer; padding: 0;` and inherit `font-family: var(--font-ui)`.

#### Scenario: Hover state
- **WHEN** hovered
- **THEN** nested `.copy-icon` MUST transition color `.15s` to `#d4d4d8`.

#### Scenario: Focus state
- **WHEN** focused via keyboard
- **THEN** `:focus-visible` outline MUST follow global focus rule.

### Requirement: Text Inputs
Inputs SHALL follow card/surface and border tokens.

#### Scenario: Default state
- **WHEN** input renders
- **THEN** it MUST use `background-color: var(--surface-card)`, `border: var(--border-w) solid var(--border-color)`, `border-radius: var(--r-sm)`, `color: var(--text-primary)`, and internal spacing based on `--space-0_75` vertical and `--space-1` horizontal.

#### Scenario: Hover and focus
- **WHEN** hovered
- **THEN** border color MAY remain `var(--border-color)`.
- **WHEN** focused
- **THEN** apply global `:focus-visible` outline and no box-shadow overrides.

### Requirement: Cards
Cards SHALL use `.card` from `style.md` without deviation.

#### Scenario: Composition
- **WHEN** used as container
- **THEN** padding MUST use `--space-2` vertical and `--space-1` horizontal unless overridden by layout recipe.

### Requirement: Tooltip
Tooltip SHALL follow `.tooltip-trigger` and `.tooltip` patterns from `style.md` including mobile/desktop behavior.

#### Scenario: Desktop hover
- **WHEN** width ≥ 768px and trigger hovered
- **THEN** `.tooltip` MUST set `opacity: 1; visibility: visible`.

#### Scenario: Mobile active
- **WHEN** width < 768px and trigger has `.active`
- **THEN** `.tooltip` MUST set `opacity: 1; visibility: visible`.

### Requirement: FAQ / Accordion
Accordion SHALL use `.faq-item`, `.faq-q`, `.faq-a` per `style.md`.

#### Scenario: Open state
- **WHEN** an item is expanded
- **THEN** `.faq-a` MUST toggle to `.active` (display: block) and `.faq-q` retains uppercase meta styling.


