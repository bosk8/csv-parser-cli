# Function-to-UI Mapping

Complete mapping of backend functionality (C++ CLI) to UI triggers, data contracts, validations, and error states.

---

## Architecture Overview

### Backend Equivalent: C++ CLI
The web UI replicates C++ CLI functionality entirely in client-side JavaScript. No backend API exists; all processing happens in the browser.

### Data Flow
```
User Action → JavaScript Event → Data Processing → UI Update
```

---

## Feature Mapping

### Feature 1: CSV File Parsing

#### Backend Function (C++ CLI)
- **Class**: `CSVParser`
- **Method**: `parse(const std::string& filename)`
- **Behavior**: Reads CSV file, parses lines, handles quoted fields, skips empty lines
- **Output**: `std::vector<std::vector<std::string>>` (array of rows, each row is array of fields)

#### UI Trigger
- **Event**: File input `change` event
- **Element**: `<input id="file-input" type="file" accept=".csv">`
- **JavaScript**: `fileInput.addEventListener('change', function(ev) { ... })`

#### Data Contract

**Input**:
- **Type**: `File` object (from browser FileReader API)
- **Format**: Plain text CSV file
- **Constraints**: `.csv` extension (enforced by `accept` attribute)

**Processing**:
- **Functionي**: `parseCSV(text)` in `app.js`
- **Algorithm**: Quote-aware line parsing (mirrors C++ `parseLine` logic)
- **Output**: `Array<Array<String>>` (JavaScript equivalent of C++ data structure)

**Output**:
- **Storage**: Global `data` variable (array of arrays)
- **Validation**: 
  - Empty file → Error message
  - Valid CSV → Populate column dropdown, show filter section

#### Validations

| Validation | Error Message | UI State |
|------------|---------------|----------|
| File is empty | "Error: CSV file is empty" | Filter section hidden |
| Parse fails (malformed) | "Error: Failed to parse CSV file" | Filter section hidden |
| File read error | Browser-native error | No file selected |

#### Error States
- **No file selected**: File input shows "No file chosen"
- **Invalid file**: Browser may prevent selection (native behavior)
- **Parse error**: Error message displayed, filter section remains hidden

#### Success State
- **File parsed**: 
  - File name displayed (`fileName.textContent = f.name`)
  - Column dropdown populated with headers
  - Filter section becomes visible (`filterSection.style.display = 'grid'`)
  - Results section hidden (if previously visible)

---

### Feature 2: Column Index Selection

#### Backend Function (C++ CLI)
- **Input**: Command-line argument `column_index` (string, converted to `size_t`)
- **Validation**: `if (args.columnIndex >= parser.getColumnCount())`
- **Error**: `"Error: Column index {index} exceeds available columns ({count})"`

#### UI Trigger
- **Element**: `<select id="col" class="b8-input"></select>`
- **Population**: After CSV file upload
- **JavaScript**: 
  ```javascript
  for (var i = 0; i < header.length; i++) {
    var opt = document.createElement('option');
    opt.value = String(i);
    opt.textContent = String(i) + (header[i] ? (' - ' + header[i]) : '');
    colSel.appendChild(opt);
  }
  ```

#### Data Contract

**Input**:
- **Type**: String (from select `value` attribute)
- **Range**: `0` to `column_count - 1`
- **Format**: Integer as string

**Processing**:
- **Conversion**: `Number(colSel.value)` → numeric index
- **Validation**: `if (idx < 0 || idx >= header.length Py)` → error

**Output**:
- **Storage**: Used directly in filter application
- **Display**: Option text shows `"{index} - {header_name}"` (e.g., "0 - Name")

#### Validations

| Validation | Error Message | UI State |
|------------|---------------|----------|
| Index < 0 | "Error: Column index must be >= 0" | Error message shown |
| Index >= column_count | "Error: Column index {index} exceeds available columns ({count})" | Error message shown, results show header only |

#### Error States
- **Invalid index selected**: 
  - Error message displayed in `#error` div
  - Results section shows header only (mirrors CLI behavior)
  - Filter can be corrected and reapplied

#### Success State
- **Valid index selected**: No error, ready for filter application

---

### Feature 3: Operator Selection

#### Backend Function (C++ CLI)
- **Input**: Command-line argument `operator` (string)
- **Parsing**: `parseOperator(argv[3])` → `FilterOperator` enum
- **Valid operators**: `==`, `!=`, `>`, `<`, `>=`, `<=`, `contains`
- **Error**: `"Invalid operator: {op}"` if not recognized

#### UI Trigger
- **Element**: `<select id="op" class="b8-input">`
- **Options**: Static HTML options (all valid operators)
- **No validation needed**: Dropdown ensures valid selection

#### Data Contract

**Input**:
- **Type**: String (from select `value`)
- **Valid values**: `"=="`, `"!="`, `">"`, `"<"`, `">="`, `"<="`, `"contains"`

**Processing**:
- **No conversion**: Used directly as string in `compare(op, a, b)` function
- **Switch logic**: Mirrors C++ `evaluateCondition` switch statement

**Output**:
- **Storage**: Used directly in filter application
- **Display**: Operator symbol shown in dropdown

#### Validations
- **None required**: Dropdown prevents invalid selections

#### Error States
- **None**: Dropdown ensures valid operator

#### Success State
- **Operator selected**: Ready for filter application

---

### Feature 4: Filter Value Input

#### Backend Function (C++ CLI)
- **Input**: Command-line argument `value` (string, passed as `argv[4]`)
- **No validation**: Accepts any string value
- **Usage**: Compared against cell values based on operator

#### UI Trigger
- **Element**: `<input id="val" type="text" class="b8-input">`
- **User input**: Free-form text input

#### Data Contract

**Input**:
- **Type**: String (from input `value`)
- **Format**: Any string (including empty)
- **Constraints**: None

**Processing**:
- **String operators** (`==`, `!=`, `contains`): Direct string comparison
- **Numeric operators** (`>`, `<`, `>=`, `<=`): Attempt `Number()` conversion

**Output**:
- **Storage**: Used directly in filter application
- **Display**: User sees entered value

#### Validations

| Validation | Error Message | UI State |
|------------|---------------|----------|
| None | N/A | N/A |

**Note**: Empty value is valid (matches empty cells for `==` operator)

#### Error States
- **None**: All values are valid (including empty)

#### Success State
- **Value entered**: Ready for filter application (or can apply with empty value)

---

### Feature 5: Filter Application

#### Backend Function (C++ CLI)
- **Class**: `CSVFilter`
- **Method**: `applyFilter(data, condition)`
- **Input**: 
  - `data`: `std::vector<std::vector<std::string>>`
  - `condition`: `FilterCondition` (column index, operator, value)
- **Output**: `std::vector<size_t>` (matching row indices)
- **Logic**: 
  - Iterate through data rows (skip header row in results)
  - Evaluate condition for each cell in specified column
  - Collect matching row indices
  - Return indices

#### UI Trigger
- **Event**: Button click or Enter key press
- **Element**: `<button id="apply" class="b8-btn">`
- **JavaScript**: `applyBtn.addEventListener('click', function(ev) { applyFilter(); })`

#### Data Contract

**Input**:
- **Global `data`**: `Array<Array<String>>` (CSV rows)
- **Column index**: `Number(colSel.value)`
- **Operator**: `opSel.value` (string)
- **Value**: `valInput.value` (string)

**Processing**:
- **Function**: `applyFilter()` in `app.js`
- **Algorithm**: 
  ```javascript
  var matches = [];
  for (var r = 1; r < data.length; r++) {  // Skip header (index 0)
    var row = data[r];
    if (row && compare(op, row[idx], val)) {
      matches.push(r);
    }
  }
  ```
- **Comparison**: `compare(op, a, b)` function (mirrors C++ logic)

**Output**:
- **Results array**: `Array<Array<String>>` containing:
  - Header row (`data[0]`)
  - Matching rows (`data[matches[i]]` for each match)
- **Display**: Formatted as CSV string (`toCSV(out)`)
- **Storage**: Displayed in `<pre id="results">` element

#### Validations

| Validation | Error Message | UI State |
|------------|---------------|----------|
| Column index out of range | "Error: Column index {index} exceeds available columns ({count})" | Error shown, results show header only |
| No data loaded | Silent (no filter applied) | No change |

#### Error States
- **Column index error**: 
  - Error message displayed
  - Results Scroll section shows header row only
  - User can correct and reapply

#### Success States

**Matching Results Found**:
- Results section becomes visible
- Filtered CSV displayed (header + matching rows)
- Export button enabled

**Empty Results**:
- Results section becomes visible
- Header row only displayed (not an error)
- Export button enabled (exports header-only CSV)

---

### Feature 6: Results Export

#### Backend Function (C++ CLI)
- **Function**: `outputResults(data, matchingRows, outputFile)`
- **Behavior**: 
  - Outputs header row
  - Outputs matching rows (based on indices)
  - Writes to stdout or file
- **Format**: Plain CSV with comma separators, newline-delimited rows

#### UI Trigger
- **Event**: Button click
- **Element**: `<button id="export" class="b8-btn">`
- **JavaScript**: `exportBtn.addEventListener('click', function(ev) { ... })`

#### Data Contract

**Input**:
- **Source**: `<pre id="results">` element `textContent`
- **Format**: Plain CSV string (header + data rows)

**Processing**:
- **Function**: Export button click handler
- **Algorithm**:
  ```javascript
  var blob = new Blob([resultsPre.textContent || ''], {type: 'text/csv'});
  var a = document.createElement('a');
  a.href = URL.createObjectURL(blob);
  a.download = 'results.csv';
  a.click();
  ```

**Output**:
- **File**: Browser download `results.csv`
- **Format**: Plain text CSV, UTF-8 encoding
- **Content**: Exact content from results display

#### Validations preserves
- **None**: Exports whatever is in results display (even if empty)

#### Error States
- **None**: Browser handles download (may prompt user for permission)

#### Success State
- **File downloaded**: Browser initiates download
- **Optional feedback**: Could show brief "Exported" message (not in current design)

---

## Data Flow Diagram

```
┌─────────────┐
│ User Action │
└──────┬──────┘
       │
       ▼
┌─────────────────────┐
│ JavaScript Event    │
│ (click, change, etc)│
└──────┬──────────────┘
       │
       ▼
┌─────────────────────┐
│ Data Processing     │
│ (parse, filter, etc)│
└──────┬──────────────┘
       │
       ├─→ [Success] ─→ UI Update (results, visibility)
       │
       └─→ [Error] ─→ Error Message Display
```

---

## Comparison: CLI vs UI

| Feature | CLI (C++) | UI (JavaScript) | Parity |
|---------|-----------|-----------------|--------|
| File input | Command-line arg | File upload | ✅ |
| CSV parsing | `CSVParser::parse()` | `parseCSV()` | ✅ |
| Column index | CLI arg (validated) | Select dropdown | ✅ |
| Operator | CLI arg (parsed) | Select dropdown | ✅ |
| Filter value | CLI arg (string) | Text input | ✅ |
| Filter logic | `CSVFilter::applyFilter()` | `applyFilter()` | ✅ |
| Results display | stdout | `<pre>` element | ✅ |
| Export | File write | Browser download | ✅ |
| Error handling | stderr messages | Error div | ✅ |

**Parity Status**: ✅ Full feature parity achieved

---

## Edge Cases & Handling

### E1: Empty CSV File
- **CLI**: Processes file, outputs header only (if header exists)
- **UI**: Shows error "CSV file is empty"
- **Note**: UI behavior is stricter (rejects empty files early)

### E2: Inconsistent Column Counts
- **CLI**: Skips rows with insufficient columns silently
- **UI**: Skips rows with insufficient columns silently
- **Parity**: ✅ Matches

### E3: Non-Numeric Data with Numeric Operators
- **CLI**: Returns false for non-numeric cells (no match)
- **UI**: Returns false for non-numeric cells (no match)
- **Parity**: ✅ Matches

### E4: Empty Filter Value
- **CLI**: Accepts empty string, matches empty cells with `==`
- **UI**: Accepts empty string, matches empty cells with `==`
- **Parity**: ✅ Matches

### E5: Quoted Fields with Commas
- **CLI**: Parsed correctly (quote-aware)
- **UI**: Parsed correctly (quote-aware)
- **Parity**: ✅ Matches

---

## API Contract (N/A)

**Note**: This is a client-side-only application. No backend API exists. All functionality is implemented in browser JavaScript, mirroring the C++ CLI behavior.

---

**Document Version**: 1.0  
**Last Updated**: Initial creation  
**Maintainer**: UI/UX System Specification

