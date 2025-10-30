# CSV Parser

A lightweight, dependency-free C++ command-line utility with a web-based UI for parsing CSV files and filtering rows based on simple column conditions. This project demonstrates mastery of file I/O, string manipulation, and data processing using only the C++17 standard library, plus a complete web UI implementation.

## Features

### CLI (Command-Line Interface)
- **CSV Parsing**: Quote-aware field handling with support for commas inside quoted fields
- **Column Filtering**: Support for 7 operators (==, !=, >, <, >=, <=, contains)
- **Simple Interface**: Unix-style command-line interface
- **Error Handling**: Graceful handling of edge cases with informative error messages
- **No Dependencies**: Uses only C++17 standard library features
- **Cross-Platform**: Compiles with both g++ and clang++

### Web UI
- **Interactive Interface**: Visual web-based UI for CSV filtering
- **File Upload**: Drag-and-drop or click to upload CSV files
- **Real-time Filtering**: Instant results with all 7 filter operators
- **Export Functionality**: Download filtered results as CSV
- **Responsive Design**: Works seamlessly on mobile and desktop
- **Accessibility**: WCAG 2.2 AA compliant with full keyboard support
- **Dark Theme**: Bosk8 Dark Minimal Mono design system

## Compilation

### Prerequisites
- C++17 compatible compiler (g++ 7+ or clang++ 5+)
- Make (optional, for using the Makefile)

### Build Instructions

```bash
# Using Makefile (recommended)
make build

# Manual compilation
g++ -std=c++17 -Wall -Wextra -O2 src/main.cpp src/csv_parser.cpp -o csv_parser

# Using clang++
clang++ -std=c++17 -Wall -Wextra -O2 src/main.cpp src/csv_parser.cpp -o csv_parser
```

### Makefile Targets

- `make build` - Compile the CSV parser
- `make clean` - Remove build artifacts
- `make run` - Run with sample data
- `make test` - Run basic tests
- `make help` - Show available targets

## Usage

### Web UI (Recommended)

The easiest way to use the CSV parser is through the web interface:

```bash
# Option 1: Serve with Python
cd web
python3 -m http.server 8000
# Open http://localhost:8000/index.html in your browser

# Option 2: Open directly in browser
# Open web/index.html in a modern browser
```

Features:
- Upload CSV files via file input
- Visual column and operator selection
- Instant filtering and results
- Export filtered results as CSV

See [csv-parser-ui/README.md](csv-parser-ui/README.md) for more details.

### CLI (Command-Line)

For command-line usage:

#### Basic Syntax

```bash
csv_parser <input_file> <column_index> <operator> <value> [output_file]
```

### Arguments

- `input_file` - Path to CSV file to parse (required)
- `column_index` - Zero-based index of column to filter (0, 1, 2, ...) (required)
- `operator` - Filter operator: ==, !=, >, <, >=, <=, contains (required)
- `value` - Value to compare against (required)
- `output_file` - Optional output file (default: stdout)

### Examples

```bash
# Filter by exact match
csv_parser data/sample.csv 0 == "John"

# Filter by numeric comparison
csv_parser data/sample.csv 1 > 25
csv_parser data/sample.csv 3 >= 60000

# Filter by contains operation
csv_parser data/sample.csv 1 contains "Smith"

# Output to file
csv_parser data/sample.csv 2 == "New York" results.csv

# Show help
csv_parser --help
```

## Output Format

The program outputs CSV data with:
1. Header row (first row of input)
2. Filtered data rows matching the specified condition
3. Proper CSV formatting with comma separators

### Example Output

```csv
Name,Age,City,Salary
John,25,New York,50000
```

## Supported Operators

| Operator | Description | Example |
|----------|-------------|---------|
| `==` | Exact match | `csv_parser data.csv 0 == "John"` |
| `!=` | Not equal | `csv_parser data.csv 0 != "John"` |
| `>` | Greater than (numeric) | `csv_parser data.csv 1 > 25` |
| `<` | Less than (numeric) | `csv_parser data.csv 1 < 30` |
| `>=` | Greater than or equal | `csv_parser data.csv 1 >= 25` |
| `<=` | Less than or equal | `csv_parser data.csv 1 <= 30` |
| `contains` | String contains | `csv_parser data.csv 0 contains "Smith"` |

## Error Handling

The program handles various error conditions gracefully:

- **Missing input file**: Displays error message and exits with code 1
- **Invalid column index**: Validates column index against available columns
- **Invalid operator**: Lists valid operators in error message
- **Empty results**: Outputs header only, exits with code 0 (not an error)
- **Malformed CSV**: Continues processing, skips problematic rows

## Test Data

The project includes several test CSV files in the `data/` directory:

- `sample.csv` - Basic test data with names, ages, cities, and salaries
- `quoted_fields.csv` - Fields with commas inside quotes
- `empty_rows.csv` - CSV with blank lines
- `special_chars.csv` - Special characters and Unicode text

## Project Structure

```
├── src/                  # C++ CLI source files
│   ├── main.cpp
│   ├── csv_parser.hpp
│   ├── csv_parser.cpp
│   └── filter_condition.hpp
├── web/                  # Web UI files
│   ├── index.html        # Main HTML interface
│   ├── bosk8.css        # Styles (Bosk8 Dark Minimal Mono)
│   └── app.js            # JavaScript application logic
├── csv-parser-ui/        # Self-contained UI package
│   ├── src/              # C++ source files
│   ├── web/              # Web UI files
│   ├── data/             # Sample CSV files
│   ├── docs/             # Complete UI/UX documentation
│   └── README.md         # UI package documentation
├── data/                 # Sample CSV test files
│   ├── sample.csv
│   ├── quoted_fields.csv
│   ├── empty_rows.csv
│   └── special_chars.csv
├── docs/                 # UI/UX documentation
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
├── bin/                  # Compiled executable
├── Makefile              # Build configuration
└── README.md             # This file
```

## Technical Details

- **Language**: C++17
- **Standard Library**: Uses only standard library features
- **Memory Management**: Automatic memory management with RAII
- **Error Handling**: Exception-based error handling
- **Performance**: Optimized for typical CSV file sizes (1000+ rows)

## Compilation Warnings

The project compiles without warnings using:
- `-Wall -Wextra` flags
- Both g++ and clang++ compilers
- C++17 standard compliance

## Limitations

- Basic quote-aware parsing (not full CSV standard compliance)
- Single filter condition per run
- In-memory processing (not suitable for very large files)
- Numeric comparison requires valid numeric data

## Testing

The project includes basic tests that can be run using the Makefile:

```bash
make test
```

The test suite verifies:
- Basic filtering functionality
- Help message display
- Numeric comparison operations

To manually test with different data files:

```bash
# Test with quoted fields
./bin/csv_parser data/quoted_fields.csv 0 == "Smith, John"

# Test with numeric comparison
./bin/csv_parser data/sample.csv 3 >= 60000

# Test empty results
./bin/csv_parser data/sample.csv 0 == "Nonexistent"
```

## Contributing

When contributing to this project:

1. **Code Style**: Follow the existing code style and ensure code compiles with `-Wall -Wextra` flags without warnings
2. **Testing**: Add tests for new features and ensure all tests pass
3. **Documentation**: Update README.md for any new features or changes
4. **Commits**: Use clear, descriptive commit messages

### Development Setup

```bash
# Clone the repository
git clone <repository-url>
cd csv-parser-cli

# Build the project
make build

# Run tests
make test

# Clean build artifacts
make clean
```

## Documentation

Complete UI/UX documentation is available in the `docs/` directory:
- [Documentation Index](docs/README.md) - Start here for documentation overview
- [Developer Handoff](docs/10-dev-handoff.md) - Implementation guide
- [Browser Test Report](docs/BROWSER-TEST-REPORT.md) - Testing results
- [Style Compliance Matrix](docs/08-style-compliance-matrix.md) - Design token mapping

The `csv-parser-ui/` folder contains a self-contained package with all UI files and documentation.

## Web UI Features

- ✅ **File Upload**: Drag-and-drop or click to select CSV files
- ✅ **Visual Filtering**: Dropdown menus for column and operator selection
- ✅ **Real-time Results**: Instant filtering and display
- ✅ **Export**: Download filtered results as CSV
- ✅ **Responsive**: Works on mobile (< 768px) and desktop (≥ 768px)
- ✅ **Accessible**: WCAG 2.2 AA compliant with ARIA attributes
- ✅ **Keyboard Support**: Full keyboard navigation including Enter key
- ✅ **Dark Theme**: Bosk8 Dark Minimal Mono design system

## License
