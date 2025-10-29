# CSV Parser CLI - Project Scope

## Overview
A lightweight, dependency-free C++ command-line utility that parses CSV files and outputs filtered rows based on simple column conditions. This project demonstrates mastery of file I/O, string manipulation, and data processing using only the C++ standard library.

## Project Scope: 8 Steps

### Step 1: Project Setup
- Create project directory structure: `src/`, `tests/`, `bin/`, `data/`
- Initialize git repository
- Create basic Makefile with targets for `build`, `clean`, `run`, `test`
- No external dependencies required—only C++17 standard library

### Step 2: Core CSV Parser Implementation
- Implement `CSVParser` class in `src/csv_parser.hpp`
- Create `parse()` method that reads CSV file line-by-line using `std::ifstream`
- Implement row splitting using `std::getline()` with comma delimiter
- Handle quoted fields that may contain commas (basic quote-aware parsing)
- Store parsed data in `std::vector<std::vector<std::string>>`

### Step 3: Column Filtering Logic
- Implement `FilterCondition` struct to represent a filter rule (column index, operator, value)
- Create `applyFilter()` method that evaluates rows against filter conditions
- Support operators: `==`, `!=`, `>`, `<`, `>=`, `<=`, `contains`
- Return filtered results as vector of row indices or filtered rows

### Step 4: CLI Argument Parsing
- Implement command-line argument parsing for:
  - Input file path (required)
  - Column index for filtering (required)
  - Filter operator (required)
  - Filter value (required)
  - Output file path (optional, default to stdout)
- Add basic validation and usage/help message

### Step 5: Main Application Logic
- Create `main()` function in `src/main.cpp`
- Parse CLI arguments
- Instantiate CSVParser and load CSV file
- Apply user-specified filter
- Output results to stdout or file with proper formatting
- Handle errors gracefully with informative error messages

### Step 6: Test Fixtures and Sample Data
- Create `data/sample.csv` with representative test data (10-20 rows, 3-4 columns)
- Create additional test CSVs with edge cases:
  - `data/quoted_fields.csv` (fields with commas inside quotes)
  - `data/empty_rows.csv` (blank lines)
  - `data/special_chars.csv` (special characters in fields)

### Step 7: Manual Testing
- Test basic filtering: filter by exact match, numeric comparison
- Test edge cases: quoted fields, empty results, non-existent columns
- Test output to file vs. stdout
- Verify error handling with invalid input
- Test performance with larger CSV files (1000+ rows)

### Step 8: Documentation and Deliverables
- Write `README.md` with:
  - Project description and features
  - Compilation instructions
  - Usage examples with sample commands
  - Output format specification
- Include Makefile with clear targets
- Add code comments for non-obvious logic
- Verify all code compiles cleanly with `g++` and `clang++`
- Ensure zero compiler warnings with `-Wall -Wextra`

## Success Criteria
- Compiles without warnings in < 3 seconds
- Parses CSV files correctly with proper field handling
- Filters rows based on specified conditions accurately
- Handles edge cases gracefully (quoted fields, missing columns, empty input)
- Runs from command-line with clear, documented arguments
- No external dependencies beyond C++17 standard library
