## Design Tokens / CSS Token Map
- Use `style.md` CSS variables exactly as defined. Do not rename.

## Spacing / Redlines
- Base font: `--fs-base`
- Container: `max-width: min(1100px, 90vw)`
- Hero padding: top ~10rem (per recipe), sides `--space-1`, bottom `--space-1`
- Tiles: `.tile { padding: 1.5rem 1rem; }`

## Snippets (HTML/CSS)
Example hero and tiles, lifted from `style.md` (no styling changes needed):

```html
<main class="bosk8">
  <div class="container">
    <section class="card border-b" style="padding:4rem 2rem; display:flex; flex-direction:column; align-items:center;">
      <h1 class="tagline">A LIGHTWEIGHT SPEC-DRIVEN FRAMEWORK</h1>
    </section>
    <section class="card grid-tiles border-b">
      <div class="tile border-r">UNIVERSAL</div>
      <div class="tile">OPEN SOURCE</div>
      <div class="tile border-r">NO API KEYS</div>
      <div class="tile">NO MCP</div>
    </section>
  </div>
</main>
```

CSV filter form (derived only from existing tokens):

```html
<form class="card" style="padding: var(--space-2) var(--space-1); display: grid; gap: var(--space-1);">
  <label class="label">COLUMN INDEX</label>
  <input type="number" style="background: var(--surface-card); border: var(--border-w) solid var(--border-color); border-radius: var(--r-sm); color: var(--text-primary); padding: var(--space-0_75) var(--space-1);" />
  <label class="label">OPERATOR</label>
  <select style="background: var(--surface-card); border: var(--border-w) solid var(--border-color); border-radius: var(--r-sm); color: var(--text-primary); padding: var(--space-0_75) var(--space-1);">
    <option>==</option><option>!=</option><option>></option><option><</option><option>>=</option><option><=</option><option>contains</option>
  </select>
  <label class="label">VALUE</label>
  <input type="text" style="background: var(--surface-card); border: var(--border-w) solid var(--border-color); border-radius: var(--r-sm); color: var(--text-primary); padding: var(--space-0_75) var(--space-1);" />
  <button class="copy-btn"><span class="meta">APPLY</span></button>
  <div class="meta">RESULTS</div>
  <pre class="meta" style="color: var(--text-subtle);"></pre>
  <button class="copy-btn"><span class="meta">EXPORT CSV</span></button>
  
  <div style="justify-self:end;" class="tooltip-trigger">
    <span class="copy-icon">i</span>
    <div class="tooltip">Filter operators: ==, !=, >, <, >=, <=, contains</div>
  </div>
</form>
```

## Accessibility Checklist
- WCAG 2.2 AA contrast using `--text-primary` / `--surface-card` / `--bg-elev1`.
- Keyboard navigation: all form controls reachable; `:focus-visible` outline per tokens.
- Tooltip: hover on desktop, `.active` toggle on mobile.

## Acceptance Checklist
- [ ] No new tokens introduced; all references use exact names from `style.md`.
- [ ] All interactive states defined (default/hover/focus/active/disabled/error/loading where applicable).
- [ ] Specs validate with strict rules; scenarios use `#### Scenario:` headers.


