# UI/UX System Documentation

Complete specification package for the CSV Parser UI, adhering strictly to the Bosk8 Dark Minimal Mono design system (`style.md`).

---

## Documentation Structure

### 1. [Executive Summary](./01-executive-summary.md)
**Purpose**: High-level overview of project goals, personas, major flows, and constraints.

**Contains**:
- Project overview and objectives
- Primary personas (Data Analyst, Developer)
- Major user flows (happy paths + edge cases)
- Technical and design constraints
- Assumptions and open questions

**Audience**: Stakeholders, product managers, team leads

---

### 2. [Information Architecture & User Flows](./02-information-architecture.md)
**Purpose**: Complete sitemap, user flow diagrams, and state machine.

**Contains**:
- Sitemap (single-page application structure)
- Detailed user flows with decision points
- Edge cases and error scenarios
- State machine diagram
- State transition rules

**Audience**: UX designers, developers

---

### 3. [Screen-by-Screen Specifications](./03-screen-specifications.md)
**Purpose**: Detailed specifications for each screen/section with wireframes, layouts, and states.

**Contains**:
- Text-based wireframes for each screen
- Layout grid specifications
- Component usage per screen
- Responsive breakpoints and rules
- All states (default, hover, focus, error, loading)
- Style token references

**Audience**: Developers, QA testers

---

### 4. [Interactive Component Library](./04-component-library.md)
**Purpose**: Complete specification for all reusable UI components.

**Contains**:
- Component purpose and props/variants
- All states (default, hover, focus, active, disabled, error)
- Exact `style.md` token references
- HTML structure examples
- CSS implementation
- Accessibility notes
- Usage examples

**Audience**: Developers, component library maintainers

---

### 5. [Function-to-UI Mapping](./05-function-to-ui-mapping.md)
**Purpose**: Map backend functionality (C++ CLI) to UI triggers, data contracts, and validations.

**Contains**:
- Architecture overview (client-side only)
- Feature mapping (parsing, filtering, export)
- Data contracts (input/output specifications)
- Validation rules
- Error states and handling
- CLI vs UI parity comparison

**Audience**: Developers, backend engineers

---

### 6. [Navigation & Routing Model](./06-navigation-routing.md)
**Purpose**: Define navigation structure, routing rules, and state management.

**Contains**:
- Single-page application structure
- Section-based navigation
- State-driven visibility rules
- Empty states and first-run experience
- State persistence (none)
- User flow navigation map

**Audience**: Developers, UX designers

---

### 7. [Accessibility Checklist](./07-accessibility-checklist.md)
**Purpose**: WCAG 2.2 AA compliance audit with implementation checklist.

**Contains**:
- WCAG 2.2 Level AA requirements
- Principle-by-principle compliance check
- Keyboard navigation flow
- Screen reader testing checklist
- Implementation checklist
- Compliance status summary

**Audience**: Developers, QA testers, accessibility auditors

---

### 8. [Style Compliance Matrix](./08-style-compliance-matrix.md)
**Purpose**: Exact mapping of every screen/component to `style.md` tokens with derivation logic.

**Contains**:
- Complete token reference (base + derived)
- Screen-by-screen token usage table
- Component token usage table
- Derived tokens summary with derivation logic
- Responsive token variations
- Compliance summary

**Audience**: Developers, designers, style system maintainers

---

### 9. [Style Decisions Log](./09-style-decisions-log.md)
**Purpose**: Timestamped log of all assumptions, derivations, conflicts, and resolutions.

**Contains**:
- Assumptions (missing information, inferred defaults)
- Derived tokens/classes with derivation logic
- Conflicts between pragmatic needs and `style.md`
- Resolutions (always favor `style.md`)
- Summary of derived tokens/classes

**Audience**: Designers, developers, future maintainers

---

### 10. [Developer Handoff](./10-dev-handoff.md)
**Purpose**: Production-ready handoff package with tokens, snippets, and acceptance criteria.

**Contains**:
- Complete CSS token map
- Derived component classes
- Spacing/redlines
- Sample HTML/CSS snippets
- React/Vue component examples (optional)
- Acceptance checklist
- Implementation notes
- Testing checklist

**Audience**: Developers (primary handoff document)

---

## Quick Reference

### For Developers Starting Implementation
1. Read [Developer Handoff](./10-dev-handoff.md) first
2. Reference [Component Library](./04-component-library.md) for component specs
3. Reference [Screen Specifications](./03-screen-specifications.md) for layout
4. Check [Style Compliance Matrix](./08-style-compliance-matrix.md) for tokens
5. Review [Function-to-UI Mapping](./05-function-to-ui-mapping.md) for behavior

### For Designers Reviewing
1. Read [Executive Summary](./01-executive-summary.md) for context
2. Review [Information Architecture](./02-information-architecture.md) for flows
3. Check [Style Decisions Log](./09-style-decisions-log.md) for design decisions
4. Verify [Style Compliance Matrix](./08-style-compliance-matrix.md) for token usage

### For QA Testers
1. Review [Screen Specifications](./03-screen-specifications.md) for expected behavior
2. Use [Accessibility Checklist](./07-accessibility-checklist.md) for a11y testing
3. Reference [Function-to-UI Mapping](./05-function-to-ui-mapping.md) for edge cases
4. Check [Developer Handoff](./10-dev-handoff.md) for acceptance criteria

---

## Style System Authority

**Single Source of Truth**: [`../style.md`](../style.md)

All visual and interaction decisions must reference `style.md`. If a needed token/pattern is missing:
1. Derive it from existing tokens using `style.md` rules
2. Log the derivation in [Style Decisions Log](./09-style-decisions-log.md)
3. Do not invent new tokens

**Absolute Rules**:
- ✅ Reference exact `style.md` token names/paths
- ✅ Log all derivations in Style Decisions Log
- ✅ Resolve conflicts in favor of `style.md`
- ❌ Do not invent new tokens

---

## Document Status

All documents are **Version 1.0** and ready for developer handoff.

**Last Updated**: Initial creation  
**Maintainer**: UI/UX System Specification

---

## Questions / Feedback

For implementation questions:
1. Check [Developer Handoff](./10-dev-handoff.md) first
2. Reference [Style Decisions Log](./09-style-decisions-log.md) for design rationale
3. Verify [Style Compliance Matrix](./08-style-compliance-matrix.md) for token usage

For design questions:
1. Refer to [`style.md`](../style.md) as single source of truth
2. Check [Style Decisions Log](./09-style-decisions-log.md) for existing decisions
3. If new decision needed, add entry to Style Decisions Log

