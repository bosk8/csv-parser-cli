## ADDED Requirements

### Requirement: Bosk8 Global UI System
The system SHALL provide global tokens, base CSS, and layout per `style.md` without inventing new tokens.

#### Scenario: Tokens exposed as CSS variables
- **WHEN** the UI loads
- **THEN** CSS variables MUST include exact names from `style.md` root block: `--font-ui`, `--fs-base`, `--bg-black`, `--bg-elev1`, `--surface-card`, `--text-primary`, `--text-muted`, `--text-subtle`, `--text-dim`, `--text-highlight`, `--accent-success`, `--border-color`, `--border-w`, `--border-outer-w`, `--shadow-tint`, `--r-sm`, `--r-md`, `--space-0_5`, `--space-0_75`, `--space-1`, `--space-1_5`, `--space-2`, `--space-4`.

#### Scenario: Responsive border widths per breakpoint
- **WHEN** viewport width ≥ 1024px
- **THEN** `--border-w` MUST equal `1.5px` and `--border-outer-w` MUST equal `2px` as defined in `style.md`.

#### Scenario: Global base styles applied
- **WHEN** rendering `html, body, main.bosk8, .container`
- **THEN** styles MUST match `style.md` Global Resets & Base and Layout recipe, including background `--bg-elev1`, font `--font-ui`, and container max width `min(1100px, 90vw)`.

### Requirement: Grid and Cards
The system SHALL implement `.grid-tiles`, `.tile`, and `.card` exactly per `style.md`.

#### Scenario: Grid columns responsive
- **WHEN** width < 768px
- **THEN** `.grid-tiles` MUST use `repeat(2, 1fr)`.
- **WHEN** width ≥ 768px
- **THEN** `.grid-tiles` MUST use `repeat(4, 1fr)`.

#### Scenario: Card depth and borders
- **WHEN** a `.card` is rendered
- **THEN** it MUST use `background-color: var(--surface-card)` and a composite box-shadow `0 0 0 var(--border-outer-w) var(--border-color), 0 1px 2px var(--shadow-tint)`.

### Requirement: Typography and Links
The system SHALL implement `.tagline`, `.meta`, `.label`, `.nav`, `.link` exactly per `style.md`.

#### Scenario: Uppercase UI labels with tracking
- **WHEN** `.tagline, .meta, .label, .nav` render
- **THEN** they MUST apply `text-transform: uppercase` and `letter-spacing: 0.05em` and `font-family: var(--font-ui)`.

#### Scenario: Link hover behavior
- **WHEN** `.link` is hovered
- **THEN** color MUST change from `var(--text-muted)` to `var(--text-primary)` with underline and `text-underline-offset: 4px`.

### Requirement: Accessibility and Focus
The system SHALL provide visible focus and meet contrast rules per `style.md`.

#### Scenario: Focus visible outline
- **WHEN** any focusable receives focus via keyboard
- **THEN** `:focus-visible` MUST apply `outline: 2px solid var(--border-color); outline-offset: 2px`.


