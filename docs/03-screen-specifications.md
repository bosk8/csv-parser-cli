# Screen-by-Screen Specifications

Detailed specifications for each screen/section with wireframes, layout grids, components, responsive rules, and all states.

---

## Screen 1: Initial State / Landing

### Purpose
Welcome screen showing hero tagline and CSV import section. First view when user loads the application.

### Wireframe (Text-based)

```
┌─────────────────────────────────────────────────────────────┐
│                                                             │
│                    [Hero Section]                           │
│              A LIGHTWEIGHT SPEC-DRIVEN                      │
│                      FRAMEWORK                              │
│                                                             │
├─────────────────────────────────────────────────────────────┤
│                                                             │
│  IMPORT CSV                                                 │
│                                                             │
│  [Choose File] [No file chosen]                            │
│                                                             │
│  [i]  [tooltip on hover/click]                             │
│                                                             │
├─────────────────────────────────────────────────────────────┤
│                                                             │
│  [Grid Tiles: UNIVERSAL | OPEN SOURCE | NO API KEYS | NO MCP]│
│                                                             │
├─────────────────────────────────────────────────────────────┤
│                                                             │
│  [FAQ Accordion Items]                                      │
│                                                             │
└─────────────────────────────────────────────────────────────┘
```

### Layout Grid
- **Container**: `min(1100px, 90vw)` max-width, centered
- **Hero Section**: Full width, `4rem 2rem` padding
- **Import Section**: Full width, `var(--space-2) var(--space-1)` padding
- **Grid**: 2 columns (mobile) → 4 columns (desktop ≥768px)
- **Vertical Spacing**: Cards stacked with no gap (border-b provides visual separation)

### Components Used
1. **Hero Section**:
   - Container: `<section class="card border-b">`
   - Tagline: `<h1 class="tagline">A LIGHTWEIGHT SPEC-DRIVEN FRAMEWORK</h1>`

2. **Import Section**:
   - Container: `<section class="card border-b">`
   - Label: `<div class="label">IMPORT CSV</div>`
   - File Input: `<input id="file-input" type="file" accept=".csv" class="b8-input">`
   - File Name Display: `<div id="file-name" class="meta-sm" style="color: var(--text-dim);"></div>`
   - Tooltip Trigger: `<div class="tooltip-trigger">` with info icon

3. **Grid Tiles**:
   - Container: `<section class="card grid-tiles border-b">`
   - 4 tiles with `.tile` class, alternating `.border-r`

4. **FAQ Section**:
   - Container: `<section class="card">`
   - FAQ items: `.faq-item` with `.faq-q` and `.faq-a`

### Responsive Rules

#### Mobile (< 768px)
- Container padding: `var(--space-4) var(--space-1)`
- Grid: 2 columns
- Hero padding: `2rem 1rem` (reduced)
- File input: Full width
- Tooltip: Click to activate (`.active` class)

#### Desktop (≥ 768px)
- Container padding: `10rem var(--space-1)` (top), `var(--space-4) var(--space-1)` (bottom)
- Grid: 4 columns
- Hero padding: `4rem 2rem`
- Tooltip: Hover to show

#### Large Desktop (≥ 1024px)
- Border width increases: `--border-w: 1.5px`, `--border-outer-w: 2px`
- Container max-width: `min(1100px, 90vw)`

### States

#### Default State
- Hero section: Visible
- Import section: Visible
- Filter section: Hidden (`display: none`)
- Results section: Hidden (`display: none`)
- File name display: Empty

#### After File Upload (State Transition)
- File name display: Shows uploaded filename
- Filter section: Becomes visible (`display: grid`)
- All other sections: Unchanged

### Style Tokens Reference
- Background: `--bg-elev1` (main), `--surface-card` (cards)
- Border: `--border-w`, `--border-color`, `--border-outer-w`
- Typography: `--font-ui`, `--text-muted`, `--text-subtle`, `--text-dim`
- Spacing: `--space-1`, `--space-2`, `--space-4`, `10rem` (container padding-top)
- Shadows: `--shadow-tint`

---

## Screen 2: Filter Configuration (After File Upload)

### Purpose
Allow user to configure filter: column index, operator, and value.

### Wireframes (Text-based)

```
┌─────────────────────────────────────────────────────────────┐
│  [Hero Section - unchanged]                                 │
├─────────────────────────────────────────────────────────────┤
│  IMPORT CSV                                                 │
│                                                             │
│  sample.csv                                                 │
│                                                             │
├─────────────────────────────────────────────────────────────┤
│  CONFIGURE FILTER                                           │
│                                                             │
│  COLUMN INDEX                                               │
│  [▼ 0 - Name              ]                                 │
│                                                             │
│  OPERATOR                                                   │
│  [▼ ==                    ]                                 │
│                                                             │
│  VALUE                                                      │
│  [________________________]                                 │
│                                                             │
│  [APPLY]                                                    │
│                                                             │
│  [error message area - empty/hidden]                        │
│                                                             │
└─────────────────────────────────────────────────────────────┘
```

### Layout Grid
- **Container**: Same as Screen 1
- **Filter Section**: Full width, `var(--space-2) var(--space-1)` padding
- **Form Grid**: `display: grid`, `gap: var(--space-1)` (vertical spacing)
- **Form Fields**: Full width, stacked vertically

### Components Used
1. **Section Container**: `<section class="card border-b" id="filter-section">`
2. **Section Label**: `<div class="label">CONFIGURE FILTER</div>`
3. **Column Selector**:
   - Label: `<label class="label" for="col">COLUMN INDEX</label>`
   - Select: `<select id="col" class="b8-input"></select>`
   - Options: Dynamically populated (`0 - Name`, `1 - Age`, etc.)
4. **Operator Selector**:
   - Label: `<label class="label" for="op">OPERATOR</label>`
   - Select: `<select id="op" class="b8-input">`
   - Options: `==`, `!=`, `>`, `<`, `>=`, `<=`, `contains`
5. **Value Input**:
   - Label: `<label class="label" for="val">VALUE</label>`
   - Input: `<input id="val" type="text" class="b8-input">`
6. **Apply Button**: `<button id="apply" class="b8-btn"><span class="meta">APPLY</span></button>`
7. **Error Display**: `<div id="error" class="meta" style="color: var(--text-subtle);" role="alert"></div>`

### Responsive Rules
- Same as Screen 1 (no changes to filter section)
- Form fields: Full width on all screen sizes
- Labels: Stack above inputs on all sizes

### States

#### Default (Initial Load)
- Filter section: Hidden (`display: none`)
- All form fields: Empty/default values
- Error message: Empty/hidden

#### File Uploaded
- Filter section: Visible (`display: grid`)
- Column dropdown: Populated with header row data
- Operator: Default to first option (`==`)
- Value input: Empty
- Error message: Hidden

#### After Apply (Success)
- Error message: Hidden
- Results section: Becomes visible (see Screen 3)

#### After Apply (Error)
- Error message: Visible with error text
  - Example: `Error: Column index 10 exceeds available columns (4)`
- Results section: Shows header only (if applicable)

#### After Apply (Empty Results)
- Error message: Hidden
- Results section: Shows header-only CSV

### Validation Rules

#### Column Index
- Must be valid integer
- Must be within range: `0 <= index < column_count`
- Error message: `Error: Column index {index} exceeds available columns ({count})`

#### Operator
- Must be one of: `==`, `!=`, `>`, `<`, `>=`, `<=`, `contains`
- No validation needed (dropdown ensures valid selection)

#### Value
- Can be empty (will match empty cells for `==` operator)
- No format validation (string or numeric as appropriate for operator)

### Keyboard Interactions
- **Tab**: Navigate through form fields in order
- **Enter**: Submit filter (triggers Apply button click)
- **Arrow Keys**: Navigate dropdown options when focused

### Accessibility
- **Labels**: All inputs have associated `<label>` elements
- **Error Announcement**: Error div uses `role="alert"` for screen reader announcement
- **Focus Management**: Focus remains on Apply button after click (or moves to results if visible)

### Style Tokens Reference
- Same as Screen 1, plus:
- Form inputs: `.b8-input` (derived tokens)
- Button: `.b8-btn` (derived tokens)
- Error: `--text-subtle` (derived from Entry 5)

---

## Screen 3: Results Display (After Filter Applied)

### Purpose
Display filtered CSV results and provide export functionality.

### Wireframe (Text-based)

```
┌─────────────────────────────────────────────────────────────┐
│  [Hero Section - unchanged]                                 │
├─────────────────────────────────────────────────────────────┤
│  [Import Section - unchanged]                               │
├─────────────────────────────────────────────────────────────┤
│  [Filter Section - unchanged]                               │
├─────────────────────────────────────────────────────────────┤
│  RESULTS                                                    │
│                                                             │
│  ┌──────────────────────────────────────────────────────┐  │
│  │ Name,Age,City,Salary                                 │  │
│  │ John,25,New York,50000                               │  │
│  │ Jane,30,Los Angeles,60000                            │  │
│  │                                                       │  │
│  └──────────────────────────────────────────────────────┘  │
│                                                             │
│  [EXPORT CSV]                                               │
│                                                             │
└─────────────────────────────────────────────────────────────┘
```

### Layout Grid
- **Container**: Same as previous screens
- **Results Section**: Full width, `var(--space-2) var(--space-1)` padding
- **Results Display**: Full width, scrollable if content overflows
- **Export Button**: Full width or inline (designer choice)

### Components Used
1. **Section Container**: `<section class="card" id="results-section">`
2. **Section Label**: `<div class="label">RESULTS</div>`
3. **Results Display**: `<pre id="results" class="meta" style="color: var(--text-subtle);"></pre>`
4. **Export Button**: `<button id="export" class="b8-btn"><span class="meta">EXPORT CSV</span></button>`

### Content Format
Results display formatted CSV:
```
Name,Age,City,Salary
John,25,New York,50000
Jane,30,Los Angeles,60000
```

- **Header Row**: Always present (first row of original CSV)
- **Data Rows**: Only rows matching filter condition
- **Formatting**: Plain CSV with comma separators, newline-delimited rows

### Responsive Rules
- Results display: Horizontal scroll if content exceeds container width
- Export button: Full width on mobile, inline on desktop (optional)
- Font size: `0.875rem` (monospace, readable at small sizes)

### States

#### Default (Hidden)
- Results section: Hidden (`display: none`)
- Results content: Empty

#### Results Displayed (Success)
- Results section: Visible (`display: grid`)
- Results content: Populated with filtered CSV
- Export button: Enabled

#### Results Empty (Header Only)
- Results section: Visible
- Results content: Header row only (not an error)
- Export button: Enabled

#### Export Triggered
- Browser download: `results.csv` file
- No state change (button remains enabled)
- Optional: Brief success feedback (not implemented in current design)

### Export Functionality
- **Trigger**: Click "EXPORT CSV" button
- **Output**: Browser download of `results.csv`
- **Content**: Exact content from results display (header + filtered rows)
- **Format**: Plain text CSV, UTF-8 encoding

### Keyboard Interactions
- **Tab**: Navigate to Export button
- **Enter/Space**: Trigger export (when button focused)
- **Arrow Keys**: Scroll results if focusable (optional)

### Accessibility
- **Results Display**: Optional `aria-live="polite"` for dynamic updates
- **Export Button**: Standard button accessibility (keyboard, screen reader)
- **Screen Reader**: Announces results update and export action

### Style Tokens Reference
- Same as previous screens, plus:
- Results text: `--text-subtle` (#a1a1aa)
- Font: `--font-ui` (JetBrains Mono)
- Font size: `0.875rem` (derived)

---

## Screen 4: Error States

### Purpose
Display validation and processing errors with clear messaging.

### Error Scenarios

#### E1: Invalid Column Index
- **Location**: Filter section, below Apply button
- **Message**: `Error: Column index {index} exceeds available columns ({count})`
- **UI**: Error div visible, results section shows header only
- **User Action**: Correct column index selection

#### E2: File Parse Error
- **Location**: Import section (or upcoming toast/notification)
- **Message**: `Error: Failed to parse CSV file`
- **UI**: Filter section remains hidden
- **User Action**: Upload valid CSV file

#### E3: Empty File
- **Location**: Import section
- **Message**: `Error: CSV file is empty`
- **UI**: Filter section remains hidden
- **User Action**: Upload file with data

#### E4: Non-CSV File Selected
- **Location**: Browser-native (file input `accept=".csv"`)
- **Message**: Browser may prevent selection
- **UI**: No file selected
- **User Action**: Select .csv file

### Error Display Component
- **Container**: `<div id="error" class="meta" style="color: var(--text-subtle);" role="alert"></div>`
- **Styling**: Uppercase text, subtle color (not alarming)
- **Accessibility**: `role="alert"` for screen reader announcement

### Error State Behavior
- **Persistence**: Error remains until:
  - User uploads new file (clears all errors)
  - User applies new filter (clears validation errors)
- **Multiple Errors**: Latest error displayed (single error div)

### Style Tokens Reference
- Error text: `--text-subtle` (#a1a1aa)
- Typography: `.meta` class (uppercase, `--text-muted` base, overridden to `--text-subtle`)
- See Style Decisions Log Entry 5

---

## Responsive Breakpoints Summary

| Breakpoint | Width | Changes |
|------------|-------|---------|
| Mobile | < 768px | 2-column grid, click tooltips, reduced hero padding |
| Desktop | ≥ 768px | 4-column grid, hover tooltips, full hero padding |
| Large Desktop | ≥ 1024px | Increased border widths (1.5px, 2px) |

---

## State Transition Diagram

```
INITIAL
 讓你 ├─→ [File Upload Success] → FILE_LOADED
  └─→ [File Upload Error] → ERROR_STATE

FILE_LOADED
  ├─→ [Apply Filter Success] → RESULTS_DISPLAYED
  ├─→ [Apply Filter Empty] → RESULTS_EMPTY
  ├─→ [Apply Filter Error] → ERROR_STATE
  └─→ [New File Upload] → FILE_LOADED (reset)

RESULTS_DISPLAYED
  ├─→ [Export CSV] → South RESULTS_DISPLAYED (no change, download triggered)
  ├─→ [Reapply Filter] → RESULTS_DISPLAYED (updated)
  ├─→ [New File Upload] → FILE_LOADED (reset)
  └─→ [Change Filter] → FILE_LOADED (results hidden)

RESULTS_EMPTY
  └─→ [Same transitions as RESULTS_DISPLAYED]

ERROR_STATE
  ├─→ [New File Upload] → FILE_LOADED (error cleared)
  ├─→ [Correct Error] → FILE_LOADED or RESULTS_DISPLAYED
  └─→ [Dismiss] → Previous state (if applicable)
```

---

**Document Version**: 1.0  
**Last Updated**: Initial creation  
**Maintainer**: UI/UX System Specification

