# CSV Parser CLI

A lightweight, dependency-free C++ command-line utility that parses CSV files and outputs filtered rows based on simple column conditions. This project demonstrates mastery of file I/O, string manipulation, and data processing using only the C++17 standard library.

## Features

- **CSV Parsing**: Quote-aware field handling with support for commas inside quoted fields
- **Column Filtering**: Support for multiple operators (==, !=, >, <, >=, <=, contains)
- **Command-Line Interface**: Simple, Unix-style command-line interface
- **Error Handling**: Graceful handling of edge cases with informative error messages
- **No Dependencies**: Uses only C++17 standard library features
- **Cross-Platform**: Compiles with both g++ and clang++

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

### Basic Syntax

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
├── src/
│   ├── main.cpp           # Main application logic
│   ├── csv_parser.hpp     # CSV parsing class
│   ├── csv_parser.cpp     # CSV parser implementation
│   └── filter_condition.hpp # Filtering logic
├── data/
│   ├── sample.csv         # Basic test data
│   ├── quoted_fields.csv  # Quoted field test data
│   ├── empty_rows.csv     # Empty row test data
│   └── special_chars.csv  # Special character test data
├── bin/                   # Compiled executable
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

## License

This project is provided as-is for educational and demonstration purposes.
