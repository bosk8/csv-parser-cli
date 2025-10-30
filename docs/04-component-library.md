# Interactive Component Library

Complete specification for all reusable UI components, with exact `style.md` token references.

---

## Component: Card

### Purpose
Container for sections of content. Provides elevated surface with subtle border.

### Props/Variants
- None (base component)

### States
- **Default**: Visible, static
- **Hover**: N/A (not interactive)
- **Focus**: N/A (not focusable)

### Style Tokens (from `style.md`)
- Background: `--surface-card` (#09090B)
- Border: `--border-outer-w` solid `--border-color`
- Shadow: `0 0 0 var(--border-outer-w) var(--border-color), 0 1px 2px var(--shadow-tint)`

### HTML Structure
```html
<section class="card border-b">
  <!-- Content -->
</section>
```

### CSS Implementation
```css
.card {
  background-color: var(--surface-card);
  box-shadow: 0 0 0 var(--border-outer-w) var(--border-color), 0 1px 2px var(--shadow-tint);
}
```

### Accessibility
- Semantic HTML: Use `<section>` or `<div>` as appropriate
- No ARIA required (presentational)

### Usage Example
```html
<section class="card border-b" style="padding: var(--space-2) var(--space-1);">
  <div class="label">IMPORT CSV</div>
  <!-- Content -->
</section>
```

---

## Component: Label

### Purpose
Uppercase label text for form fields and sections.

### Props/Variants
- None (base component)

### States
- **Default**: Visible, `--text-muted` color

### Style Tokens (from `style.md`)
- Font family: `--font-ui`
- Text transform: `uppercase`
- Letter spacing: `0.05em`
- Color: `--text-muted` (#E8E8E8)

### HTML Structure
```html
<label class="label" for="input-id">COLUMN INDEX</label>
```

### CSS Implementation
```css
.label {
  font-family: var(--font-ui);
  text-transform: uppercase;
  letter-spacing: 0.05em;
  color: var(--text封面);
}
```

### Accessibility
- Use `<label>` element with `for` attribute when labeling form inputs
- Use `<div class="label">` for section headers
- Screen readers: Native label association

### Usage Example
```html
<label class="label" for="col">COLUMN INDEX</label>
<select id="col" class="b8-input"></select>
```

---

## Component: Input (Text)

### Purpose
Single-line text input for filter values.

### Props/Variants
- Type: `text` (default), `number` (if numeric-only needed)

### States
- **Default**: Border `--border-color`, background `--surface-card`
- **Focus**: Border color changes to `--text-subtle`, outline appears
- **Hover**: N/A (not hoverable)
- **Disabled**: Reduce opacity (if needed)
- **Error**: Use `--text-subtle` border or error class (derived)

### Style Tokens
- **From `style.md`**: `--surface-card`, `--border-w`, `--border-color`, `--r-sm`, `--text-primary`
- **From spacing**: `--space-0_75`, `--space-1`
- **Derived**: Focus border color (`--text-subtle`)

### HTML Structure
```html
<input id="val" type="text" class="b8-input" />
```

### CSS Implementation
```css
.b8-input {
  background-color: var(--surface-card);
  border: var(--border-w) solid var(--border-color);
  border-radius: var(--r-sm);
  color: var(--text-primary);
  padding: var(--space-0_75) var(--space-1);
  font-family: var(--font-ui);
  font-size: 1rem;
}

.b8-input:focus {
  border-color: var(--text-subtle);
  outline: 2px solid var(--border-color);
  outline-offset: 2px;
}
```

### Accessibility
- **ARIA**: Use `aria-label` if label not visible
- **Keyboard**: Tab to focus, type to enter value
- **Screen readers**: Associate with `<label>` using `for`/`id`

### Usage Example
```html
<label class="label" for="val">VALUE</label>
<input id="val" type="text" class="b8-input" />
```

---

## Component: Select (Dropdown)

### Purpose
Dropdown selector for column index and operator selection.

### Props/Variants
- Options: Dynamically populated (column dropdown) or static (operator dropdown)

### States
- **Default**: Same as input
- **Focus**: Same as input
- **Open**: Browser-native dropdown (OS-dependent styling)
- **Hover (option)**: OS-dependent
- **Selected**: OS-dependent

### Style Tokens
- Same as `.b8-input` (reuses input styles)

### HTML Structure
```html
<select id="col" class="b8-input">
  <option value="0">0 - Name</option>
  <option value="1">1 - Age</option>
</-based>
```

### CSS Implementation
- Reuses `.b8-input` styles
- Dropdown arrow: May need custom styling for consistency (browser-dependent)

### Accessibility
- **Keyboard**: Tab to focus, Arrow keys to navigate, Enter to select
- **Screen readers**: Announce option text and selected state
- **ARIA**: Native `<select>` is accessible by default

### Usage Example
```html
<label class="label" for="op">OPERATOR</label>
<select id="op" class="b8-input">
  <option>==</option>
  <option>!=</option>
  <option>></option>
  <!-- etc -->
</select>
```

---

## Component: File Input

### Purpose
File upload control for CSV files.

### Props/Variants
- Accept: `.csv` (restrict file type)

### States
- **Default**: Styled wrapper, native file button (OS-dependent)
- **Focus**: Native focus styles
- **File Selected**: Filename displayed separately

### Style Tokens
- Input wrapper: `.b8-input` (if wrapper used)
- Native button: OS-dependent (not styled)

### HTML Structure
```html
<input id="file-input" type="file" accept=".csv" class="b8-input" />
```

### CSS Implementation
- Apply `.b8-input` to file input (may have limited effect on native button)
- Consider wrapper div for full styling control

### Accessibility
- **Keyboard**: Tab to focus, Enter/Space to open file dialog
- **Screen readers**: Announce "file input" and selected filename
- **ARIA**: Native `<input type="file">` is accessible

### Usage Example
```html
<label class="label" for="file-input">IMPORT CSV</label>
<input id="file-input" type="file" accept=".csv" class="b8-input" />
<div id="file-name" class="meta-sm" style="color: var(--text-dim);"></div>
```

---

## Component: Button (Primary Action)

### Purpose
Trigger filter application and CSV export.

### Props/Variants
- Type: `button` (default) or `submit` (if in form)

### States
- **Default**: Transparent background, `--text-muted` color
- **Hover**: Color changes to `--text-primary`
- **Focus**: Outline appears (`--border-color`)
- **Active**: Slight opacity reduction (optional)
- **Disabled**: Reduce opacity, cursor not-allowed (if needed)

### Style Tokens
- **From `style.md`**: `.copy-btn` pattern, `.meta` typography
- **Derived**: `.b8-btn` class (extends `.copy-btn`)

### HTML Structure
```html
<button id="apply" class="b8-btn" type="button">
  <span class="meta">APPLY</span>
</button>
```

### CSS Implementation
```css
.b8-btn {
  display: inline-flex;
  align-items: center;
  gap: var(--space-0_75);
  background: transparent;
  border: none;
  cursor: pointer;
  padding: var(--space-0_75) var(--space-1);
  font-family: var(--font-ui);
}

.b8-btn:hover {
  color: var(--text-primary);
}

.b8-btn:focus-visible {
  outline: 2px solid var(--border-color);
  outline-offset: 2px;
}
```

### Accessibility
- **Keyboard**: Tab to focus, Enter/Space to activate
- **Screen readers**: Button text announced ("APPLY button")
- **ARIA**: No additional ARIA needed (semantic button)

### Usage Example
```html
<button id="apply" class="b8-btn">
  <span class="meta">APPLY</span>
</button>
```

---

## Component: Tooltip

### Purpose
Contextual help text on hover (desktop) or click (mobile).

### Props/Variants
- Position: `bottom` (default, above trigger)
- Content: Plain text

### States
- **Default**: Hidden (`opacity: 0`, `visibility: hidden`)
- **Hover (desktop)**: Visible (`opacity: 1`, `visibility: visible`)
- **Active (mobile)**: Visible (via `.active` class)

### Style Tokens (from `style.md`)
- Background: `--surface-card`
- Border: `--border-w` solid `--border-color`
- Padding: `--space-0_5` (0.5rem)
- Font size: `0.625rem` (from tooltip pattern)
- Color: `--text-subtle`
- Arrow: `--border-color` (border-top)

### HTML Structure
```html
<div class="tooltip-trigger">
  <span class="copy-icon">i</span>
  <div class="tooltip">Upload a CSV. First row is treated as header.</div>
</div>
```

### CSS Implementation
- See `style.md` lines 176-187 for complete CSS

### Accessibility
- **Keyboard**: Focus trigger to show tooltip (consider `aria-describedby`)
- **Screen readers**: Use `aria-label` on trigger or `aria-describedby` with tooltip `id`
- **ARIA**: `aria-describedby="tooltip-id"` recommended

### Usage Example
```html
<div class="tooltip-trigger" aria-label="Information about CSV upload">
  <span class="copy-icon" aria-hidden="true">i</span>
  <div class="tooltip" id="csv-help">Upload a CSV. First row is treated as header.</div>
</div>
```

---

## Component: Results Display (Pre-formatted)

### Purpose
Display filtered CSV results as plain text.

### Props/Variants
- Content: CSV text (header + data rows)

### States
- **Default**: Visible with `--text-subtle` color
- **Empty**: Shows header only (not an error state)
- **Scroll**: Horizontal scroll if content overflows

### Style Tokens
- **From `style.md`**: `--font-ui`, `--text-subtle`
- **Derived**: Font size `0.875rem`, line height `1.5`

### HTML Structure
```html
<pre id="results" class="meta" style="color: var(--text-subtle);"></pre>
```

### CSS Implementation
```css
#results {
  font-family: var(--font-ui);
  color: var(--text-subtle);
  font-size: 0.875rem;
  line-height: 1.5;
  overflow-x: auto;
  white-space: pre;
}
```

### Accessibility
- **Keyboard**: Scrollable with arrow keys if focusable
- **Screen readers**: Read as plain text (monospace helps code/data readability)
- **ARIA**: Optional `role="textbox"` or `aria-live="polite"` for dynamic updates

### Usage Example
```html
<div class="label">RESULTS</div>
<pre id="results" class="meta" style="color: var(--text-subtle);"></pre>
```

---

## Component: Error Message

### Purpose
Display validation and processing errors.

### Props/Variants
- Severity: Informational (not critical/blocking)

### States
- **Default**: Hidden (empty text)
- **Visible**: Displays error message

### Style Tokens
- **From `style.md`**: `.meta` typography
- **Derived**: `--text-subtle` color (Entry 5 in Style Decisions Log)

### HTML Structure
```html
<div id="error" class="meta" style="color: var(--text-subtle);"></div>
```

### CSS Implementation
```css
.error-meta {
  font-family: var(--font-ui);
  text-transform: uppercase;
  letter-spacing: 0.05em;
  color: var(--text-subtle);
  font-size: 0.875rem;
}
```

### Accessibility
- **ARIA**: Use `aria-live="polite"` or `aria-live="assertive"` for dynamic errors
- **Screen readers**: Announce error messages automatically if `aria-live` used
- **Role**: Optional `role="alert"` for critical errors

### Usage Example
```html
<div id="error" class="meta" style="color: var(--text-subtle);" role="alert" aria-live="polite"></div>
```

---

## Component: FAQ Accordion Item

### Purpose
Expandable FAQ section for help content.

### Props/Variants
- Question text
- Answer text

### States
- **Default**: Collapsed (answer hidden)
- **Expanded**: Answer visible (`.active` class on `.faq-a`)

### Style Tokens (from `style.md`)
- Item border: `--border-w` solid `--border-color`
- Hover background: `#18181b` (derived, Entry 8 observation)
- Question: `.faq-q` (uppercase, `--text-muted`)
- Answer: `.faq-a` (`--text-subtle`, font-size `0.8rem`)

### HTML Structure
```html
<div class="faq-item">
  <button class="faq-q">WHAT OPERATORS ARE SUPPORTED?</button>
  <div class="faq-a">==, !=, >, <, >=, <=, contains</div>
</div>
```

### CSS Implementation
- See `style.md` lines 192-198 for complete CSS

### Accessibility
- **Keyboard**: Tab to focus question button, Enter/Space to toggle
- **Screen readers**: Announce question text and expanded/collapsed state
- **ARIA**: Use `aria-expanded="true/false"` on button, `aria-controls="answer-id"` linking to answer

### Usage Example
```html
<div class="faq-item">
  <button class="faq-q" aria-expanded="false" aria-controls="faq-1-answer">
    WHAT OPERATORS ARE SUPPORTED?
  </button>
  <div class="faq-a" id="faq-1-answer">==, !=, >, <, >=, <=, contains</div>
</div>
```

---

## Component: Grid Tiles

### Purpose
Feature grid display (Universal, Open Source, etc.).

### Props/Variants
- Columns: 2 (mobile) → 4 (desktop ≥768px)

### States
- **Default**: Static tiles

### Style Tokens (from `style.md`)
- Grid: `repeat(2, 1fr)` mobile, `repeat(4, 1fr)` desktop
- Tile padding: `1.5rem 1rem`
- Border: `--border-r` (right border on selected tiles)

### HTML Structure
```html
<section class="card grid-tiles border-b">
  <div class="tile border-r">UNIVERSAL</div>
  <div class="tile">OPEN SOURCE</div>
  <!-- etc -->
</section>
```

### CSS Implementation
- See `style.md` lines 166-171 for complete CSS

### Accessibility
- **Semantic HTML**: Use `<section>` for container, `<div>` for tiles
- **Screen readers**: Read tile text as plain content

### Usage Example
```html
<section class="card grid-tiles border-b">
  <div class="tile border-r">UNIVERSAL</div>
  <div class="tile">OPEN SOURCE</div>
  <div class="tile border-r">NO API KEYS</div>
  <div class="tile">NO MCP</div>
</section>
```

---

## Component Summary Table

| Component | Base Tokens | Derived Tokens | States | Accessibility |
|-----------|-------------|----------------|--------|---------------|
| Card | `--surface-card`, `--border-outer-w`, `--border-color`, `--shadow-tint` | None | Default | Semantic HTML |
| Label | `--font-ui`, `--text-muted` | None | Default | `<label>` with `for` |
| Input | `--surface-card`, `--border-w`, `--border-color`, `--r-sm`, `--text-primary` | Focus border: `--text-subtle` | Default, Focus | `<label>` association |
| Select | Same as Input | None | Default, Focus, Open | Native `<select>` |
| File Input | Same as Input | None | Default, Selected | Native `<input type="file">` |
| Button | `.copy-btn`, `.meta` | `.b8-btn` class | Default, Hover, Focus | Semantic `<button>` |
| Tooltip | `--surface-card`, `--border-w`, `--border-color`, `--text-subtle` | None | Hidden, Visible | `aria-describedby` |
| Results | `--font-ui`, `--text-subtle` | Font size `0.875rem` | Default, Empty | `aria-live` optional |
| Error | `.meta`, `--text-subtle` | `.error-meta` class | Hidden, Visible | `aria-live`, `role="alert"` |
| FAQ | `--border-w`, `--border-color`, `--text-muted`, `--text-subtle` | Hover `#18181b` | Collapsed, Expanded | `aria-expanded`, `aria-controls` |
| Grid Tiles | Grid columns, padding | None | Default | Semantic HTML |

---

**Document Version**: 1.0  
**Last Updated**: Initial creation  
**Maintainer**: UI/UX System Specification

