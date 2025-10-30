## ADDED Requirements

### Requirement: CSV UI Screens
The system SHALL provide a minimal web UI mirroring CLI functionality with import, filter, and export using Bosk8 components.

#### Scenario: Home / Hero
- **WHEN** user lands on `/`
- **THEN** render `main.bosk8 > .container > .card` hero with `.tagline` and a CTA to import CSV, following the Layout Recipe in `style.md`.

#### Scenario: Import CSV
- **WHEN** user selects a `.csv` file
- **THEN** the UI MUST show file name, parse header row client-side, and populate a column index selector.

#### Scenario: Configure Filter
- **WHEN** header is available
- **THEN** show inputs for `column_index`, `operator` (one of `==, !=, >, <, >=, <=, contains`), and `value` using Inputs spec.

#### Scenario: Apply Filter
- **WHEN** user applies filter
- **THEN** UI MUST display results in a `.card` with header row followed by matched rows formatted as CSV lines.

#### Scenario: Export Results
- **WHEN** results exist
- **THEN** UI MUST offer an export action to download a `.csv` file of the rendered results.

### Requirement: Error and Empty States
The system SHALL present errors matching CLI semantics.

#### Scenario: Invalid column index
- **WHEN** `column_index` exceeds available columns
- **THEN** show inline meta text (uppercase) explaining the error within a `.card`, using `--text-subtle` and border tokens.

#### Scenario: Empty results
- **WHEN** no rows match
- **THEN** show a `.card` with header-only preview and meta text: `NO MATCHES FOUND`.

### Requirement: Navigation & Routing
The system SHALL support simple route rules without SSR requirements.

#### Scenario: Routes
- **WHEN** navigating
- **THEN** `/` displays hero + import; `/filter` displays configuration and results (client-side routing OK).

### Requirement: Accessibility
The system SHALL meet WCAG 2.2 AA and follow focus rules from `style.md`.

#### Scenario: Keyboard navigation
- **WHEN** navigating inputs and buttons via keyboard
- **THEN** focus-visible outlines MUST be shown, and all actions are operable with keyboard only.


