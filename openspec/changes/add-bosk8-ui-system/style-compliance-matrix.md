## Style Compliance Matrix

### Global
- Root tokens: `--font-ui`, `--fs-base`, `--bg-black`, `--bg-elev1`, `--surface-card`, `--text-*`, `--accent-success`, `--border-color`, `--border-w`, `--border-outer-w`, `--shadow-tint`, `--r-sm`, `--r-md`, `--space-*`
- Media rule: `@media (min-width: 1024px)` → `--border-w: 1.5px; --border-outer-w: 2px`

### Components
- Card: `background: var(--surface-card)`, `box-shadow: 0 0 0 var(--border-outer-w) var(--border-color), 0 1px 2px var(--shadow-tint)`
- Grid: `.grid-tiles` columns 2 → 4 at 768px
- Typography: `.tagline, .meta, .label, .nav` → uppercase, letter-spacing: `0.05em`, `font-family: var(--font-ui)`
- Links: `.link` default `--text-muted`, hover `--text-primary` + underline offset 4px
- Tooltip: `.tooltip-trigger`, `.tooltip` per exact positions and transitions
- FAQ: `.faq-*` per borders, hover, toggling `.active`
- Inputs (derived): background `--surface-card`, border `--border-w var(--border-color)`, radius `--r-sm`, padding `--space-0_75`/`--space-1`

### Screens
- Hero: `main.bosk8` container/padding per Layout Recipe
- Filter: result table rendered as CSV lines in `.card` with borders `--border-w`


