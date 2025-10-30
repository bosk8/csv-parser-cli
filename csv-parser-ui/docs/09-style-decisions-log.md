# Style Decisions Log

This document tracks all assumptions, derivations, conflicts, and resolutions related to `style.md` compliance.

## Format
Each entry includes:
- **Timestamp**: Decision date/version
- **Category**: Assumption | Derivation | Conflict | Question
- **Context**: What triggered the decision
- **Decision**: What was decided
- **Style.md Reference**: Exact token/pattern used or derivation logic
- **Rationale**: Why this decision was made

---

## Entries

### Entry 1: Input Field Styles
- **Timestamp**: 2024-01-XX (Initial)
- **Category**: Derivation
- **Context**: `style.md` provides no explicit input/select/form field styles
- **Decision**: Create `.b8-input` class using existing tokens
- **Style.md Reference**: 
  - Background: `--surface-card` (#09090B)
  - Border: `--border-w` solid `--border-color`
  - Border radius: `--r-sm` (4px)
  - Text color: `--text-primary` (#fff)
  - Padding: `--space-0_75` vertical, `--space-1` horizontal
- **Rationale**: Inputs should match card surfaces for consistency; subtle borders follow Bosk8 pattern
- **Implementation**: 
  ```css
  .b8-input {
    background-color: var(--surface-card);
    border: var(--border-w) solid var(--border-color);
    border-radius: var(--r-sm);
    color: var(--text-primary);
    padding: var(--space-0_75) var(--space-1);
  }
  ```

### Entry 2: Input Focus State
- **Timestamp**: 2024-01-XX (Initial)
- **Category**: Derivation
- **Context**: `style.md` provides `:focus-visible` outline style, but needs input-specific enhancement
- **Decision**: Use existing `:focus-visible` pattern with input-specific border color change
- **Style.md Reference**: 
  - Focus outline: `2px solid var(--border-color)` (from `style.md` line 212)
  - Input focus border: Lighten border on focus (transition to `--text-subtle` tint)
- **Rationale**: Maintains accessibility while providing visual feedback
- **Implementation**:
  ```css
  .b8-input:focus {
    border-color: var(--text-subtle);
    outline: 2px solid var(--border-color);
    outline-offset: 2px;
  }
  ```

### Entry 3: Button Styles (Action Buttons)
- **Timestamp**: 2024-01-XX (Initial)
- **Category**: Derivation
- **Context**: `style.md` provides `.copy-btn` pattern but no general action button
- **Decision**: Extend `.copy-btn` pattern for primary actions; create `.b8-btn` variant
- **Style.md Reference**:
  - Base: `.copy-btn` pattern (transparent background, inline-flex, gap)
  - Text: `.meta` class (uppercase, letter-spacing 0.05em, `--text-muted`)
  - Hover: Use existing hover pattern from `.copy-btn`
- **Rationale**: Maintains visual consistency with existing button pattern
- **Implementation**:
  ```css
  .b8-btn {
    display: inline-flex;
    align-items: center;
    gap: var(--space-0_75);
    background: transparent;
    border: none;
    cursor: pointer;
    padding: var(--space-0_75) var(--space-1);
  }
  .b8-btn:hover { color: var(--text-primary); }
  ```

### Entry 4: Results Display (Pre-formatted Text)
- **Timestamp**: 2024-01-XX (Initial)
- **Category**: Derivation
- **Context**: Results need monospace display with subtle styling
- **Decision**: Use `<pre>` with `.meta` class and `--text-subtle` color
- **Style.md Reference**:
  - Font: `--font-ui` (JetBrains Mono)
  - Color: `--text-subtle` (#a1a1aa)
  - Typography: `.meta` class pattern
- **Rationale**: Results are data/code-like; subtle color indicates secondary content
- **Implementation**:
  ```css
  #results {
    font-family: var(--font-ui);
    color: var(--text-subtle);
    font-size: 0.875rem;
    line-height: 1.5;
    overflow-x: auto;
  }
  ```

### Entry 5: Error Message Styling
- **Timestamp**: 2024-01-XX (Initial)
- **Category**: Derivation
- **Context**: Error states need distinct but non-alarming styling
- **Decision**: Use `.meta` class with `--text-subtle` (same as results)
- **Style.md Reference**:
  - Typography: `.meta` (uppercase, `--text-muted` base, but override to `--text-subtle`)
  - Color: `--text-subtle` (#a1a1aa)
- **Rationale**: Errors are informational; subtle color matches results section pattern
- **Note**: Could use accent color, but `style.md` only provides `--accent-success` (green), not error/warning
- **Implementation**: Inline style override or `.error-meta` class

### Entry 6: File Name Display
- **Timestamp**: 2024-01-XX (Initial)
- **Category**: Derivation
- **Context**: File name shown after upload needs subtle display
- **Decision**: Use `.meta` class with `--text-dim` for very subtle indication
- **Style.md Reference**:
  - Typography: `.meta-sm` (0.75rem, uppercase)
  - Color: `--text-dim` (#71717a)
- **Rationale**: File name is metadata; dim color indicates secondary info
- **Implementation**: `.meta-sm` class with `--text-dim` color

### Entry 7: Section Spacing (Gap)
- **Timestamp**: 2024-01-XX (Initial)
- **Category**: Derivation
- **Context**: Filter section uses `display: grid; gap: var(--space-1)`
- **Decision**: Use `--space-1` (1rem) for vertical gaps between form elements
- **Style.md Reference**: `--space-1: 1rem` (from spacing tokens)
- **Rationale**: Consistent with container padding patterns in `style.md`
- **Note**: This matches existing usage in `web/index.html`

### Entry 8: Card Padding Variations
- **Timestamp**: 2024-01-XX (Initial)
- **Category**: Observation
- **Context**: Cards use different padding values (`4rem 2rem`, `var(--space-2) var(--space FU-1)`)
- **Decision**: Accept existing variations as intentional
- **Style.md Reference**: Hero section uses `4rem 2rem` (matches `--space-4` and `--space-2`)
- **Rationale**: Hero section needs more padding; form sections use standard spacing
- **No change needed**: Current implementation follows `style.md` patterns

### Entry 9: File Input Styling
- **Timestamp**: 2024-01-XX (Initial)
- **Category**: Derivation
- **Context**: Native file input needs Bosk8 styling
- **Decision**: Apply `.b8-input` class; browser-native file picker will use OS styling
- **Style.md Reference**: `.b8-input` (derived in Entry 1)
- **Rationale**: File input button is OS-controlled; input wrapper can be styled
- **Implementation**: Apply `.b8-input` to `<input type="file">`; may need wrapper div for full control

### Entry 10: Select Dropdown Styling
- **Timestamp**: 2024-01-XX (Initial)
- **Category**: Derivation
- **Context**: `<select>` elements need Bosk8 styling
- **Decision**: Apply `.b8-input` class; dropdown arrow styling may be OS-dependent
- **Style.md Reference**: `.b8-input` (derived in Entry 1)
- **Rationale**: Selects should match text inputs visually
- **Implementation**: Apply `.b8-input` to `<select>`; consider custom arrow if cross-browser consistency needed

### Entry 11: Loading State
- **Timestamp**: 2024-01-XX (Initial)
- **Category**: Assumption
- **Context**: No loading indicator pattern in `style.md`
- **Decision**: Use subtle text animation or static "Processing..." message
- **Style.md Reference**: 
  - Typography: `.meta-sm` with `--text-dim`
  - Animation: `style.md` says "keep transitions under 200ms"
- **Rationale**: File parsing is fast (< 200ms for typical files), so minimal loading state needed
- **Implementation**: Optional; may not be necessary if parsing is instantaneous

### Entry 12: Success State (Export Confirmation)
- **Timestamp**: 2024-01-XX (Initial)
- **Category**: Derivation
- **Context**: No toast/notification pattern in `style.md`
- **Decision**: Use subtle inline text feedback or browser-native download afirmation
- **Style.md Reference**: 
  - Color: `--accent-success` (#22c55e) for success indicators
  - Typography: `.meta-sm`
- **Rationale**: Downloads are handled by browser; optional "Exported" text can use success color
- **Implementation**: Optional brief "Exported successfully" text using `--accent-success`

---

## Conflicts & Resolutions

### Conflict 1: Error Color
- **Context**: Need error state color but `style.md` only provides `--accent-success`
- **Resolution**: Use `--text-subtle` for errors (informational tone). If critical errors needed later, derive warning color from existing palette (e.g., slight red tint to `--text-subtle`).
- **Status**: Resolved with derivation

### Conflict 2: Button Primary Action
- **Context**: No clear "primary button" pattern in `style.md`
- **Resolution**: Use transparent button pattern (`.copy-btn`) with hover states. If stronger CTAs needed, consider subtle border or background using `--surface-card` with `--border-color`.
- **Status**: Resolved with derivation

---

## Summary of Derived Tokens/Classes

| Class/Pattern | Base Tokens | Usage |
|--------------|-------------|-------|
| `.b8-input` | `--surface-card`, `--border-w`, `--border-color`, `--r-sm`, `--text-primary`, `--space-0_75`, `--space-1` | All form inputs and selects |
| `.b8-btn` | `.copy-btn` pattern, `.meta` typography | Primary action buttons |
| `.error-meta` | `.meta`, `--text-subtle` | Error messages |
| `.file-name` | `.meta-sm`, `--text-dim` | File metadata display |
| `#results pre` | `--font-ui`, `--text-subtle`, `.meta` pattern | Results display |

---

**Document Version**: 1.0  
**Last Updated**: Initial creation  
**Maintainer**: UI/UX System Specification

