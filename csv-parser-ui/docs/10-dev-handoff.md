# Developer Handoff Artifacts

Complete design-to-development handoff package with tokens, CSS, HTML snippets, and acceptance criteria.

---

## Design Tokens / CSS Token Map

### Complete CSS Variables (from `style.md`)

```css
:root {
  /* Typography */
  --font-ui: JetBrains Mono, ui-monospace, SFMono-Regular, Menlo, Monaco, Consolas, Liberation Mono, DejaVu Sans Mono, Courier New, monospace;
  --fs-base: clamp(16px, calc(15.2px + 0.25vw), 20px);

  /* Colors - Background */
  --bg-black: #000;
  --bg-elev1: #0A0A0A;
  --surface-card: #09090B;

  /* Colors - Text */
  --text-primary: #fff;
  --text-muted: #e8e8e8;
  --text-subtle: #a1a1aa;
  --text-dim: #71717a;
  --text-highlight: #f4f4f5;

  /* Colors - Accent */
  --accent-success: #22c55e;

  /* Borders */
  --border-color: rgb(39 39 42);
  --border-w: 1px;          /* elevated to 1.5px ≥1024px */
  --border-outer-w: 1px;    /* elevated to 2px ≥1024px */

  /* Shadows */
  --shadow-tint: #0000000d;

  /* Border Radius */
  --r-sm: 4px;
  --r-md: 6px;

  /* Spacing */
  --space-0_5: 0.5rem;
  --space-0_75: 0.75rem;
  --space-1: 1rem;
  --space-1_5: 1.5rem;
  --space-2: 2rem;
  --space-4: 4rem;
}

@media (min-width: 1024px) {
  :root {
    --border-w: 1.5px;
    --border-outer-w: 2px;
  }
}
```

### Derived Component Classes

```css
/* Input Styles (Derived - Entry 1, Style Decisions Log) */
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

/* Button Styles (Derived - Entry 3, Style Decisions Log) */
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

/* Error Message (Derived - Entry 5, Style Decisions Log) */
.error-meta {
  font-family: var(--font-ui);
  text-transform: uppercase;
  letter-spacing: 0.05em;
  color: var(--text-subtle);
  font-size: 0.875rem;
}

/* Results Display (Derived - Entry 4, Style Decisions Log) */
#results {
  font-family: var(--font-ui);
  color: var(--text-subtle);
  font-size: 0.875rem;
  line-height: 1.5;
  overflow-x: auto;
  white-space: pre;
}
```

---

## Spacing / Redlines

### Container Layout

```
Container Max Width: min(1100px, 90vw)
Container Padding:
  - Mobile: var(--space-4) var(--space-1)
  - Desktop Top: 10rem (hero spacing)
  - Desktop Bottom: var(--space-4) var(--space-1)
```

### Section Spacing

```
Hero Section Padding: 4rem 2rem
Import Section Padding: var(--space-2) var(--space-1)
Filter Section Padding: var(--space-2) var(--space-1)
Results Section Padding: var(--space-2) var(--space-1)

Form Grid Gap: var(--space-1) (vertical spacing between form fields)
```

### Component Spacing

```
Input Padding: var(--space-0_75) vertical, var(--space-1) horizontal
Button Padding: var(--space-0_75) var(--space-1)
Tooltip Padding: var(--space-0_5)
FAQ Question Padding: 1.25rem 1.75rem
FAQ Answer Padding: 0 1.75rem 1.25rem
Tile Padding: 1.5rem 1rem
```

### Border Widths

```
Default: var(--border-w) = 1px
Default Outer: var(--border-outer-w) = 1px
≥1024px: var(--border-w) = 1.5px
≥1024px: var(--border-outer-w) = 2px
```

---

## Sample HTML/CSS Snippets

### Complete Import Section

```html
<section class="card border-b" style="padding: var(--space-2) var(--space-1); display: grid; gap: var(--space-1);">
  <div class="label">IMPORT CSV</div>
  <input id="file-input" type="file" accept=".csv" class="b8-input" />
  <div id="file-name" class="meta-sm" style="color: var(--text-dim);"></div>
  <div class="tooltip-trigger" style="justify-self:end;" aria-label="Information about CSV upload">
    <span class="copy-icon" aria-hidden="true">i</span>
    <div class="tooltip" id="csv-help">Upload a CSV. First row is treated as header.</div>
  </div>
</section>
```

### Complete Filter Section

```html
<section class="card border-b" id="filter-section" style="display:none; padding: var(--space-2) var(--space-1); display: grid; gap: var(--space-1);">
  <div class="label">CONFIGURE FILTER</div>
  
  <label class="label" for="col">COLUMN INDEX</label>
  <select id="col" class="b8-input"></select>
  
  <label class="label" for="op">OPERATOR</label>
  <select id="op" class="b8-input">
    <option>==</option>
    <option>!=</option>
    <option>></option>
    <option><</option>
    <option>>=</option>
    <option><=</option>
    <option>contains</option>
  </select>
  
  <label class="label" for="val">VALUE</label>
  <input id="val" type="text" class="b8-input" />
  
  <button id="apply" class="b8-btn" type="button">
    <span class="meta">APPLY</span>
  </button>
  
  <div id="error" class="meta error-meta" role="alert" aria-live="assertive"></div>
</section>
```

### Complete Results Section

```html
<section class="card" id="results-section" style="display:none; padding: var(--space-2) var(--space-1); display: grid; gap: var(--space-1);">
  <div class="label">RESULTS</div>
  <pre id="results" class="meta" style="color: var(--text-subtle);" aria-live="polite"></pre>
  <button id="export" class="b8-btn" type="button">
    <span class="meta">EXPORT CSV</span>
  </button>
</section>
```

### FAQ Accordion Item (with ARIA)

```html
<div class="faq-item">
  <button class="faq-q" aria-expanded="false" aria-controls="faq-1-answer">
    WHAT OPERATORS ARE SUPPORTED?
  </button>
  <div class="faq-a" id="faq-1-answer">==, !=, >, <, >=, <=, contains</div>
</div>
```

### JavaScript: FAQ Toggle with ARIA

โย่ง```javascript
document.querySelectorAll('.faq-q').forEach(function(q){
  q.addEventListener('click', function(){
    var a = q.nextElementSibling;
    var isExpanded = a.classList.contains('active');
    a.classList.toggle('active');
    q.setAttribute('aria-expanded', !isExpanded);
  });
});
```

---

## React/Vue Component Examples (Optional)

### React: Input Component

```jsx
import React from 'react';

export function B8Input({ id, label, type = 'text', ...props }) {
  return (
    <>
      <label className="label" htmlFor={id}>
        {label.toUpperCase()}
      </label>
      <input
        id={id}
        type={type}
        className="b8-input"
        {...props}
      />
    </>
  );
}
```

### React: Button Component

```jsx
import React from 'react';

export function B8Button({ children, onClick, type = 'button', ...props }) {
  return (
    <button
      type={type}
      className="b8-btn"
      onClick={onClick}
      {...props}
    >
      <span className="meta">{children}</span>
    </button>
  );
}
```

---

## Acceptance Checklist

### Visual Design ✅ (~)

- [ ] All colors match `style.md` tokens exactly
- [ ] Typography uses JetBrains Mono (fallbacks as specified)
- [ ] All spacing uses `style.md` spacing tokens
- [ ] Border widths match `style.md` (responsive breakpoints)
- [ ] Cards use correct shadow pattern (`--border-outer-w` + `--shadow-tint`)
- [ ] All text is uppercase with 0.05em letter-spacing (where specified)
- [ ] Grid tiles: 2 columns (mobile) → 4 columns (desktop ≥768px)

### Component Implementation ✅

- [ ] `.b8-input` class applied to all inputs and selects
- [ ] `.b8-btn` class applied to all buttons
- [ ] `.card` class applied to all section containers
- [ ] `.label` class applied to all labels
- [ ] `.meta` class applied to metadata text
- [ ] Tooltips use `.tooltip-trigger` and `.tooltip` classes
- [ ] FAQ items use `.faq-item`, `.faq-q`, `.faq-a` classes

### Functionality ✅

- [ ] File upload triggers CSV parsing
- [ ] Column dropdown populates after file upload
- [ ] Filter applies correctly with all 7 operators
- [ ] Results display shows filtered CSV
- [ ] Export downloads `results.csv` file
- [ ] Error messages display correctly
- [ ] Empty results show header only (not error)

### Responsive Design ✅

- [ ] Mobile layout (< 768px): 2-column grid, click tooltips
- [ ] Desktop layout (≥ 768px): 4-column grid, hover tooltips
- [ ] Large desktop (≥ 1024px): Border widths increase
- [ ] Container max-width: `min(1100px, 90vw)`
- [ ] Results scroll horizontally if content overflows

### Accessibility ✅

- [ ] All form inputs have associated `<label>` elements
- [ ] All buttons have accessible names
- [ ] Focus indicators visible (2px outline with `--border-color`)
- [ ] Keyboard navigation works (Tab, Enter, Arrow keys)
- [ ] ARIA attributes:
  - [ ] `aria-expanded` on FAQ buttons
  - [ ] `aria-controls` on FAQ buttons
  - [ ] `aria-describedby` on tooltip triggers
  - [ ] `aria-live` on results and error displays
  - [ ] `role="alert"` on error messages
- [ ] Color contrast meets WCAG 2.2 AA (primary text: 21:1 ✅)

### State Management ✅

- [ ] Filter section appears after file upload
- [ ] Results section appears after filter apply
- [ ] New file upload resets filter and results
- [ ] Error messages clear on new file upload
- [ ] Results update in place when filter reapplied

### Edge Cases ✅

- [ ] Empty CSV file shows error
- [ ] Invalid column index shows error
- [ ] Empty filter results show header only
- [ ] Non-numeric data with numeric operators handled gracefully
- [ ] Quoted fields with commas parsed correctly
- [ ] Large files handled (browser memory limits)

### Browser Compatibility ✅

- [ ] Chrome/Edge (latest)
- [ ] Firefox (latest)
- [ ] Safari (latest)
- [ ] FileReader API support
- [ ] Blob/URL.createObjectURL support

---

## Implementation Notes

### CSS Import Order
1. CSS Variables (`:root`)
2. Global resets
3. Base styles (html, body, main)
4. Component classes (card, label, input, button)
5. Utility classes (border-b, border-r, etc.)
6. Derived classes (.b8-input, .b8-btn, etc.)
7. Media queries (responsive breakpoints)

### JavaScript Structure
- File parsing: Quote-aware CSV parsing (mirrors C++ logic)
- Filter logic: `compare(op, a, b)` function (mirrors C++ logic)
- State management: DOM-based (show/hide sections, update content)
- Event handlers: File input change, button clicks, keyboard (Enter)

### File Organization
```
web/
  ├── index.html
  ├── bosk8.css
  └── app.js
```

### Testing Checklist
- [ ] Manual testing with `data/sample.csv`
- [ ] Test all 7 operators
- [ ] Test error cases (invalid column, empty file)
- [ ] Test empty results
- [ ] Test export functionality
- [ ] Keyboard-only navigation
- [ ] Screen reader testing (NVDA/JAWS/VoiceOver)

---

## Known Limitations

1. **No State Persistence**: Page refresh resets all state
2. **No URL Routing**: Cannot bookmark/share filter state
3. **Single Filter**: Only one filter condition per session (matches CLI)
4. **File Size**: Limited by browser memory (typically ~100MB max)
5. **Browser File Dialog**: File input styling is OS-dependent

---

## Future Enhancements (Out of Scope)

- Multi-filter support
- URL state serialization
- localStorage for file/filter persistence
- Drag-and-drop file upload
- CSV preview table (instead of plain text)
- Sort/pagination for results

---

## Questions / Clarifications

If implementation questions arise:
1. Refer to `style.md` for visual decisions
2. Refer to Style Decisions Log for derived tokens
3. Refer to Function-to-UI Mapping for behavior specifications
4. Refer to Component Library for component APIs

---

**Document Version**: 1.0  
**Last Updated**: Initial creation  
**Maintainer**: UI/UX System Specification  
**Handoff Ready**: ✅ Yes

