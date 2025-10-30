# Navigation & Routing Model

---

## Application Type
**Single-Page Application (SPA)** with state-based navigation (no traditional routing).

---

## Routing Model

### Route Structure
- **Single Route**: `/` (root, `index.html`)
- **No URL Parameters**: State is managed in JavaScript, not URL
- **No Hash Routing**: No `#` fragments used
- **No History API**: No `pushState` or `replaceState` (state changes don't update URL)

### Navigation Mechanism
State-driven visibility of sections:
- Sections shown/hidden via `display: none` / `display: grid`
- State stored in JavaScript variables (not URL)
- Navigation = Section visibility changes

---

## Global Navigation

### Primary Navigation
**None** — single-page application, no navigation menu.

### Secondary Navigation
**None** — all functionality on one page.

### Breadcrumbs
**Not applicable** — single page, no hierarchy.

---

## Section-Based Navigation

### Section Order (Top to Bottom)

1. **Hero Section**
   - Always visible
   - Static content (tagline)

2. **Import CSV Section**
   - Always visible
   - Interactive: File upload

3. **Filter Configuration Section**
   - **Conditional**: Visible after file upload
   - **Initial**: Hidden (`display: none`)
   - **Trigger**: File successfully parsed
   - **Interactive**: Column select, operator select, value input, apply button

4. **Results Section**
   - **Conditional**: Visible after filter applied
   - **Initial**: Hidden (`display: none`)
   - **Trigger**: Filter successfully applied
   - **Interactive**: Export button

5. **Features Grid**
   - Always visible
   - Static content (4 tiles)

6. **FAQ Section**
   - Always visible
   - Interactive: Accordion toggles

### Section Visibility Rules

| Section | Initial State | Shows When | Hides When |
|---------|--------------|------------|------------|
| Hero | Visible | Always | Never |
| Import | Visible | Always | Never |
| Filter | Hidden | File uploaded successfully | Never (remains visible) |
| Results | Hidden | Filter applied successfully | New file uploaded |

---

## Empty States

### Initial Load (No File Uploaded)
- **Hero**: Visible
- **Import**: Visible (empty file input)
- **Filter**: Hidden
- **Results**: Hidden
- **Grid/FAQ**: Visible

**User Actions Available**:
- Upload CSV file

---

## First-Run States

### First-Time User Experience
- **Same as Initial Load**: No special first-run state
- **No onboarding**: Application is self-explanatory
- **No tutorials**: Tooltips provide contextual help

**Guidance Available**:
- Hero tagline: "A LIGHTWEIGHT SPEC-DRIVEN FRAMEWORK"
- Info tooltip on Import section: "Upload a CSV. First row is treated as header."
- FAQ section: Explains operators and empty results behavior

---

## State Persistence

### Session Persistence
- **None**: No localStorage or sessionStorage
- **Page refresh**: Resets to initial state
- **File upload**: Not persisted across refresh
- **Filter configuration**: Not persisted across refresh
- **Results**: Not persisted across refresh

### Reasons
- Simple utility: No need for persistence
- Privacy: User data (CSV files) never stored
- Stateless design: Matches CLI behavior (one-time execution)

---

## Navigation Patterns

### Pattern 1: Progressive Disclosure
Sections appear as user progresses:
1. Upload file → Filter section appears
2. Apply filter → Results section appears

### Pattern 2: Reset on New File
Uploading new file:
- Resets filter section (new column dropdown)
- Hides results section
- Clears error messages

### Pattern 3: In-Place Updates
Reapplying filter:
- Results section updates in place (doesn't hide/show)
- Previous results replaced

---

## URL Structure (N/A)

**No URL routing**:
- No query parameters
- No hash fragments
- No path parameters
- Single URL: Application root

**Future Considerations** (if routing needed):
- Could add hash routing: `/#filter?col=0&op==&val=John`
- Could add query params: `/?file=uploaded&filter=applied`
- **Not in current scope**: Keep simple, stateless design

---

## Deep Linking (N/A)

**Not supported**:
- Cannot share URL with specific file/filter state
- Cannot bookmark filter configuration
- **Reason**: Client-side only, no state serialization

---

## Back/Forward Navigation

### Browser Back/Forward
- **Behavior**: Standard browser navigation (loads fresh page)
- **State**: Resets to initial state (no state restoration)
- **No History Entries**: State changes don't create history entries

### Internal Back Navigation
- **Not applicable**: Linear workflow, no back button needed

---

## Navigation Summary Table

| Navigation Type | Implementation | State Management |
|----------------|----------------|------------------|
| Section visibility | CSS `display` property | JavaScript variables |
| File upload state | Global `data` array | In-memory |
| Filter state | Form field values | DOM elements |
| Results state | `<pre>` element content | DOM elements |
| Error state | Error div text | DOM elements |
| URL routing | None | N/A |
| Deep linking | Not supported | N/A |
| State persistence | None | N/A |

---

## User Flow Navigation Map

```
START (Page Load)
  │
  ├─→ [Upload File] ──→ Filter Section Appears
  │                      │
  │                      ├─→ [Apply Filter] ──→ Results Section Appears
  │                      │                      │
  │                      │                      └─→ [Export CSV] ──→ Download
  │                      │
  │                      └─→ [Upload New File] ──→ Reset (Filter Visible, Results Hidden)
  │
  └─→ [View FAQ] ──→ Expand/Collapse FAQ Items (No Navigation)
```

**Notes**:
- Linear workflow (no branching navigation)
- Reset occurs only on new file upload
- All sections stack vertically (no modal overlays)

---

**Document Version**: 1.0  
**Last Updated**: Initial creation  
**Maintainer**: UI/UX System Specification

