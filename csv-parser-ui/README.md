# CSV Parser UI

A lightweight, dependency-free C++ command-line utility with a web-based UI for parsing CSV files and filtering rows based on simple column conditions.

## Project Structure

```
csv-parser-ui/
├── src/              # C++ source files (CLI)
│   ├── main.cpp
│   ├── csv_parser.hpp
│   ├── csv_parser.cpp
│   └── filter_condition.hpp
├── web/              # Web UI files
│   ├── index.html    # Main HTML
│   ├── bosk8.css    # Styles (Bosk8 Dark Minimal Mono)
│   └── app.js        # JavaScript application logic
├── data/             # Sample CSV test files
│   ├── sample.csv
│   ├── quoted_fields.csv
│   ├── empty_rows.csv
│   └── special_chars.csv
├── docs/             # Complete UI/UX documentation
│   ├── README.md                    # Documentation index
│   ├── 01-executive-summary.md
│   ├── 02-information-architecture.md
│   ├── 03-screen-specifications.md
│   ├── 04-component-library.md
│   ├── 05-function-to-ui-mapping.md
│   ├── 06-navigation-routing.md
│   ├── 07-accessibility-checklist.md
│   ├── 08-style-compliance-matrix.md
│   ├── 09-style-decisions-log.md
│   ├── 10-dev-handoff.md
│   ├── FINAL-SANITY-CHECK.md
│   └── BROWSER-TEST-REPORT.md
├── Makefile          # Build configuration
├── project-scope.md  # Project scope and requirements
└── README.md         # This file
```

## Features

### CLI (C++)
- **CSV Parsing**: Quote-aware field handling with support for commas inside quoted fields
- **Column Filtering**: Support for 7 operators (==, !=, >, <, >=, <=, contains)
- **Command-Line Interface**: Simple, Unix-style command-line interface
- **Error Handling**: Graceful handling of edge cases with informative error messages
- **No Dependencies**: Uses only C++17 standard library features

### Web UI
- **File Upload**: Drag-and-drop or click to upload CSV files
- **Interactive Filtering**: Visual interface for configuring filters
- **Real-time Results**: Instant filtering and results display
- **Export Functionality**: Download filtered results as CSV
- **Responsive Design**: Works on mobile and desktop
- **Accessibility**: WCAG 2.2 AA compliant
- **Keyboard Support**: Full keyboard navigation

## Quick Start

### Web UI
Simply open `web/index.html` in a modern browser or serve it with a local web server:

```bash
cd web
python3 -m http.server 8000
# Then open http://localhost:8000/index.html
```

### CLI
Build and run:

```bash
make build
./bin/csv_parser data/sample.csv 0 == "John"
```

See the main [README.md](../README.md) for detailed usage instructions.

## Documentation

Complete UI/UX documentation is available in the `docs/` directory:
- Start with [docs/README.md](docs/README.md) for documentation overview
- See [docs/10-dev-handoff.md](docs/10-dev-handoff.md) for developer implementation guide
- Check [docs/BROWSER-TEST-REPORT.md](docs/BROWSER-TEST-REPORT.md) for test results

## Style System

The UI adheres strictly to the **Bosk8 Dark Minimal Mono** design system. All visual decisions reference `style.md` tokens. See [docs/08-style-compliance-matrix.md](docs/08-style-compliance-matrix.md) for complete token mapping.

## Browser Compatibility

Tested and compatible with:
- Chrome/Edge (latest)
- Firefox (latest)
- Safari (latest)

Requires modern browser support for:
- FileReader API
- Blob API
- CSS Variables
- CSS Grid

## License

Same as parent project.
