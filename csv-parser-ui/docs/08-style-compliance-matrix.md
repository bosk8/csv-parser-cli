# Style Compliance Matrix

Complete mapping of every screen and component to exact `style.md` token usage. All derived tokens include derivation logic.

---

## Token Reference (from `style.md`)

### Base Tokens (Direct from `style.md`)
- `--font-ui`: JetBrains Mono, ui-monospace, ...
- `--fs-base`: clamp(16px, calc(15.2px + 0.25vw), 20px)
- `--bg-black`: Pflanzen #000000
- `--bg-elev1`: #0A0A0A
- `--surface-card`: #09090B
- `--text-primary`: #FFFFFF
- `--text-muted`: #E8E8E8
- `--text-subtle`: #A1A1AA
- `--text-dim`: #71717A
- `--text-highlight`: #F4F4F5
- `--accent-success`: #22C55E
- `--border-color`: rgb(39 39 42)
- `--shadow-tint`: #0000000d
- `--r-sm`: 4px
- `--r-md`: 6px
- `--border-w`: 1px (1.5px ≥1024px)
- `--border-outer-w`: 1px (2px ≥1024px)
- `--space-0_5`: 0.5rem
- `--space-0_75`: 0.75rem
- `--space-1`: 1rem
- `--space-1_5`: 1.5rem
- `--space-2`: 2rem
- `--space-4`: 4rem

### Typography Classes (from `style.md`)
- `.tagline`: uppercase, letter-spacing 0.05em, `--text-muted`, font-size 1rem
- `.meta`: uppercase, letter-spacing 0.05em, `--text-muted`
- `.meta-sm`: font-size 0.75rem
- `.meta-md`: font-size 0.875rem
- `.label`: uppercase, letter-spacing 0.05em, `--text-muted`

---

## Screen-by-Screen Token Usage

### Screen 1: Initial State / Landing

| Element | Token/Class | Source | Notes |
|---------|-------------|--------|-------|
| `main.bosk8` background | `--bg-elev1` | `style.md` line 118 | Direct token |
| `main.bosk8` padding-top | `10rem` | `style.md` line 117 | Direct value |
| `main.bosk8` padding | `var(--space-4) var(--space-1)` | `style.md` line 116 | Direct tokens |
| `.container` max-width | `min(1100px, 90vw)` | `style.md` line 120 | Direct value |
| Hero section background | `--surface-card` | `style.md` line 127 | Via `.card` class |
| Hero section border | `--border-outer-w` + `--border-color` | `style.md` lines 128-129 | Via `.card` class |
| Hero section shadow | `--shadow-tint` | `style.md` line 128 | Via `.card` class |
| Hero section padding | `4rem 2rem` | `style.md` line 221 | Direct value (matches `--space-4` and `--space-2`) |
| `.tagline` font-family | `--font-ui` | `style.md` line 140 | Via `.tagline` class |
| `.tagline` text-transform | `uppercase` | `style.md` line 141 | Via `.tagline` class |
| `.tagline` letter-spacing | `0.05em` | `style.md` line 142 | Via `.tagline` class |
| `.tagline` color | `--text-muted` | `style.md` line 143 | Via `.tagline` class |
| `.tagline` font-size | `1rem` | `style.md` line 145 | Via `.tagline` class |
| Import section background | `--surface-card` | `style.md` line 127 | Via `.card` class |
| Import section border | `--border-outer-w` + `--border-color` | `style.md` lines 128-129 | Via `.card` class |
| Import section padding | `var(--space-2) var(--space-1)` | `style.md` line 16 (HTML) | Direct tokens |
| `.label` font-family | `--font-ui` | `style.md` line 140 | Via `.label` class |
| `.label` text-transform | `uppercase` | `style.md` line 141 | Via `.label` class |
| `.label` letter-spacing | `0.05em` | `style.md` line 142 | Via `.label` class |
| `.label` color | `--text-muted` | `style.md` line 143 | Via `.label` class |
| File input border | `--border-w` + `--border-color` | **Derived** (Entry 1) | `.b8-input` class |
| File input background | `--surface-card` | **Derived** (Entry 1) | `.b8-input` class |
| File input border-radius | `--r-sm` | **Derived** (Entry 1) | `.b8-input` classèles |
| File input padding | `var(--space-0_75) var(--space-1)` | **Derived** (Entry 1) | `.b8-input` class |
| File name display font-size | `0.75rem` | `style.md` line 146 | Via `.meta-sm` class |
| File name display color | `--text-dim` | **Derived** (Entry 6) | Style Decisions Log |
| Tooltip background | `--surface-card` | `style.md` line 179 | Via `.tooltip` class |
| Tooltip border | `--border-w` + `--border-color` | `style.md` line 179 | Via `.tooltip` class |
| Tooltip padding | `--space-0_5` | `style.md` line 180 | Via `.tooltip` class |
| Tooltip font-size | `0.625rem` | `style.md` line 180 | Via `.tooltip` class |
| Tooltip color | `--text-subtle` | `style.md` line 180 | Via `.tooltip` class |
| Grid tiles background | `--surface-card` | `style.md` line 127 | Via `.card` class |
| Grid columns (mobile) | `repeat(2, 1fr)` | `style.md` line 167 | Via `.grid-tiles` class |
| Grid columns (desktop) | `repeat(4, 1fr)` | `style.md` line 169 | Via `.grid-tiles` class |
| Tile padding | `1.5rem 1rem` | `style.md` line 170 | Via `.tile` class |
| Tile border-right | `--border-w` + `--border-color` | `style.md` line 131 | Via `.border-r` class |
| FAQ item border-bottom | `--border-w` + `--border-color` | `style.md` line 192 | Via `.faq-item` class |
| FAQ item hover background | `#18181b` | `style.md` line 193 | Direct value (derived observation) |
| FAQ question font-size | `0.75rem` | `style.md` line 194 | Via `.faq-q` class |
| FAQ question color | `--text-muted` | `style.md` line 194 | Via `.faq-q` class |
| FAQ question hover color | `#fff` (text-primary dereference) | `style.md` line 195 | Direct value |
| FAQ answer font-size | `0.8rem` | `style.md` line 196 | Via `.faq-a` class |
| FAQ answer color | `--text-subtle` | `style.md` line 196 | Via `.faq-a` class |

---

### Screen 2: Filter Configuration

| Element | Token/Class | Source | Notes |
|---------|-------------|--------|-------|
| Filter section background | `--surface-card` | `style.md` line 127 | Via `.card` class |
| Filter section border | `--border-outer-w` + `--border-color` | `style.md` lines 128-129 | Via `.card` class |
| Filter section padding | `var(--space-2) var(--space-1)` | `style.md` line 26 (HTML) | Direct tokens |
| Filter section gap | `var(--space-1)` | `style.md` line 16 (HTML) | Direct token |
| Column select border | `--border-w` + `--border-color` | **Derived** (Entry 1) | `.b8-input` class |
| Column select background | `--surface-card` | **Derived** (Entry 1) | `.b8-input` class |
| Column select border-radius | `--r-sm` | **Derived** (Entry 1) | `.b8-input` class |
| Column select padding | `var(--space-0_75) var(--space-1)` | **Derived** (Entry 1) | `.b8-input` class |
| Column select color | `--text-primary` | **Derived** (Entry 1) | `.b8-input` class |
| Column select focus border | `--text-subtle` | **Derived** (Entry 2) | Style Decisions Log |
| Operator select | Same as Column select | **Derived** (Entry 1, 10) | `.b8-input` class |
| Value input | Same as Column select | **Derived** (Entry 1, 2) | `.b8-input` class |
| Apply button font-family | `--font-ui` | **Derived** (Entry 3) | `.b8-btn` class |
| Apply button color | `.meta` class (uppercase, `--text-muted`) | **Derived** (Entry 3) | `.b8-btn` + `.meta` |
| Apply button hover color | `--text-primary` | **Derived** (Entry 3) | `.b8-btn:hover` |
| Apply button padding | `var(--space-0_75) var(--space-1)` | **Derived** (Entry 3) | `.b8-btn` class |
| Error message font-family | `--font-ui` | Via `.meta` class | `.meta` class |
| Error message text-transform | `uppercase` | Via `.meta` class | `.meta` class |
| Error message color | `--text-subtle` | **Derived** (Entry 5) | Style Decisions Log |
| Error message font-size | `0.875rem` | Via `.meta-md` (assumed) | **Derived** |

---

### Screen 3: Results Display

| Element | Token/Class | Source | Notes |
|---------|-------------|--------|-------|
| Results section background | `--surface-card` | `style.md` line 127 | Via `.card` class |
| Results section border | `--border-outer-w` + `--border-color` | `style.md` lines 128-129 | Via `.card` class |
| Results section padding | `var(--space-2) var(--space-1)` | `style.md` line 40 (HTML) | Direct tokens |
| Results display font-family | `--font-ui` | `style.md` line 107 | Via `#results` selector |
| Results display color | `--text-subtle` | **Derived** (Entry 4) | Style Decisions Log |
| Results display font-size | `0.875rem` | **Derived** (Entry 4) | Style Decisions Log |
| Export button | Same as Apply button | **Derived** (Entry 3) | `.b8-btn` class |

---

## Component Token Usage

### Component: Card
| Property | Token | Source |
|----------|-------|--------|
| background-color | `--surface-card` | `style.md` line 127 |
| box-shadow | `--border-outer-w`, `--border-color`, `--shadow-tint` | `style.md` line 128 |

### Component: Input (`.b8-input`)
| Property | Token | Source | Derivation |
|----------|-------|--------|------------|
| background-color | `--surface-card` | `style.md` line 127 | Entry 1 |
| border | `--border-w` solid `--border-color` | `style.md` lines 81, 80 | Entry 1 |
| border-radius | `--r-sm` | `style.md` line 86 | Entry 1 |
| color | `--text-primary` | `style.md` line 72 | Entry 1 |
| padding | `var(--space-0_75) var(--space-1)` | `style.md` lines 90, 91 | Entry 1 |
| border-color (focus) | `--text-subtle` | `style.md` line 74 | Entry 2 |

### Component: Button (`.b8-btn`)
| Property | Token | Source | Derivation |
|----------|-------|--------|------------|
| font-family | `--font-ui` | `style.md` line 65 | Entry 3 |
| background | `transparent` | `.copy-btn` pattern | Entry 3 |
| padding | `var(--space-0_75) var(--space-1)` | `style.md` lines 90, 91 | Entry 3 |
| color (default) | `--text-muted` | `.meta` class | Entry 3 |
| color (hover) | `--text-primary` | `style.md` line 72 | Entry 3 |

### Component: Results Display
| Property | Token | Source | Derivation |
|----------|-------|--------|------------|
| font-family | `--font-ui` | `style.md` line 65 | Entry 4 |
| color | `--text-subtle` | `style.md` line 74 | Entry 4 |
| font-size | `0.875rem` | **Derived** | Entry 4 (assumed `.meta-md`) |

### Component: Error Message
| том Property | Token | Source | Derivation |
|----------|-------|--------|------------|
| font-family | `--font-ui` | Via `.meta` | Entry 5 |
| text-transform | `uppercase` | Via `.meta` | Entry 5 |
| color | `--text-subtle` | `style.md` line 74 | Entry 5 |
| font-size | `0.875rem` | Via `.meta-md` (assumed) | Entry 5 |

---

## Derived Tokens Summary

| Derived Token/Class | Base Tokens | Derivation Logic | Entry |
|---------------------|-------------|------------------|-------|
| `.b8-input` | `--surface-card`, `--border-w`, `--border-color`, `--r-sm`, `--text-primary`, `--space-0_75`, `--space-1` | Inputs match card surfaces; use existing border/radius patterns | Entry 1 |
| `.b8-input:focus` border-color | `--text-subtle` | Lighten border on focus for feedback | Entry 2 |
| `.b8-btn` | `.copy-btn` pattern, `.meta` typography | Extend existing button pattern | Entry 3 |
| `#results` color | `--text-subtle` | Results are data; use subtle color for secondary content | Entry 4 |
| `#results` font-size | `0.875rem` | Assume `.meta-md` size for readability | Entry 4 |
| `.error-meta` color | `--text-subtle` | Errors are informational; use subtle color (no error color in `style.md`) | Entry 5 |
| `.file-name` color | `--text-dim` | File name is metadata; use dim color | Entry 6 |

---

## Responsive Token Variations

| Breakpoint | Token Change | Source |
|------------|--------------|--------|
| ≥ 1024px | `--border-w: 1.5px` | `style.md` line 98 |
| ≥ 1024px | `--border-outer-w: 2px` | `style.md` line 98 |
| ≥ 768px | Grid: 2 cols → 4 cols | `style.md` line 169 |
| ≥ 768px | Tooltip: click → hover | `style.md` line 185 |

---

## Compliance Summary

### Direct Token Usage
- ✅ All base tokens from `style.md` used correctly
- ✅ All typography classes from `style.md` used correctly
- ✅ All spacing tokens from `style.md` used correctly
- ✅ All color tokens from `style.md` used correctly

### Derived Tokens
- ✅ All derivations logged in Style Decisions Log
- ✅ All derivations follow `style.md` patterns
- ✅ No new tokens invented (only derived)

### Violations
- ❌ None identified

---

**Document Version**: 1.0  
**Last Updated**: Initial creation  
**Maintainer**: UI/UX System Specification

