# Information Architecture & User Flows

## Sitemap

### Single-Page Application Structure

```
/ (root)
└── index.html (single page, all functionality)
    ├── Hero Section
    │   └── Tagline
    ├── Import CSV Section
    │   ├── File Input
    │   ├── File Name Display
    │   └── Info Tooltip
    ├── Filter Configuration Section (conditional)
    │   ├── Column Index Selector
    │   ├── Operator Selector
    │   ├── Value Input
    │   ├── Apply Technology Button
    │   └── Error Message Display
    ├── Results Section (conditional)
    │   ├── Results Display (pre-formatted CSV)
    │   └── Export CSV Button
    ├── Features Grid
    │   └── 4 Tiles (Universal, Open Source, No API Keys, No MCP)
    └── FAQ Section
        ├── Operators Support FAQ
        └── Empty Results Handling FAQ
```

### State-Based Navigation

No traditional routing; navigation is state-driven:
- **Initial State**: Hero + Import section visible
- **File Uploaded**: Import + Filter sections visible
- **Filter Applied**: Import + Filter + Results sections visible

---

## User Flows

### Flow 1: Successful Filter Application (Primary Happy Path)

**Actor**: Data Analyst  
**Precondition**: User has a CSV file ready

```
START
  ↓
[Visit Application]
  ↓
[View Hero + Import Section]
  ↓
[Click File Input]
  ↓
[Select CSV File from OS]
  ↓
[System Parses CSV]
  │
  ├─→ [Parse Error?]
  │     └─→ [Display Error Message] → END
  │
  └─→ [Success]
        ↓
[File Name Displayed]
  ↓
[Filter Section Appears]
  ↓
[Column Dropdown Populated]
  ↓
[User Selects Column Index]
  ↓
[User Selects Operator]
  ↓
[User Enters Filter Value]
  ↓
[User Clicks "APPLY"]
  ↓
[System Applies Filter Client-Side]
  │
  ├─→ [Filter Error?]
  │     └─→ [Display Error Message]
  │           ↓
  │     [Results Section Shows Header Only]
  │           ↓
  │     END
  │
  └─→ [Filter Success]
        ↓
[Results Section Appears]
  ↓
[Filtered CSV Displayed (Header + Matching Rows)]
  ↓
[User Reviews Results]
  ↓
[User Clicks "EXPORT CSV"]
  ↓
[Browser Downloads results.csv]
  ↓
END
```

**Success Criteria**:
- File uploads without error
- Filter section appears automatically
- Filter applies correctly
- Results display accurately
- Export downloads correct CSV

---

### Flow 2: Empty Results

**Actor**: Data Analyst  
**Precondition**: User has uploaded a CSV and configured a filter

```
[User Applies Filter]
  ↓
[Filter Returns Zero Matches]
  ↓
[Results Section Appears]
  ↓
[Header Row Only Displayed]
  ↓
[Export Still Available]
  ↓
END
```

**Notes**:
- This is not an error state (matches CLI behavior)
- Header row must always be present
- Export produces valid CSV with header only

---

### Flow 3: Invalid Column Index

**Actor**: Any User  
**Precondition**: CSV uploaded, filter section visible

```
[User Selects Column Index > Available Columns]
  ↓
OR
[User Manually Enters Invalid Index]
  ↓
[User Clicks "APPLY"]
  ↓
[System Validates Column Index]
  ↓
[Validation Fails]
  ↓
[Error Message Displayed]
  ├─→ "Error: Column index X exceeds available columns (Y)"
  ↓
[Results Section Shows Header Only]
  ↓
END explained
```

**Error Message Format**: `Error: Column index {index} exceeds available columns ({count})`

---

### Flow 4: File Parse Error

**Actor**: Any User  
**Precondition**: User attempts to upload a file

```
[User Selects File]
  ↓
[System Attempts to Read File]
  ↓
[File Read Fails or Invalid Format]
  ↓
[Error Message Displayed]
  ├─→ "Error: Failed to parse CSV file"
  ↓
[Filter Section Remains Hidden]
  ↓
END
```

**Handling**:
- Empty files → Error message
- Corrupted files → Error message
- Non-CSV files → Browser may reject (accept=".csv" on input)

---

### Flow 5: Numeric Comparison with Totally Non-Numeric Data

**Actor**: Developer  
**Precondition**: CSV uploaded, user selects numeric operator (>, <, >=, <=)

```
[User Selects Numeric Operator]
  ↓
[User Enters Numeric Value]
  ↓
[User Clicks "APPLY"]
  ↓
[System Processes Filter]
  │
  ├─→ [Cell Value Converts to Number?]
  │     └─→ [Numeric Comparison Performed]
  │
  └─→ [Cell Value Non-Numeric?]
        └─→ [Row Skipped / Returns False]
              ↓
        [Results Show Only Numeric Matches]
  ↓
END
```

**Behavior**:
- Non-numeric cells are treated as failed comparison (not an error)
- Only numeric cells matching condition are returned
- Matches CLI behavior

---

### Flow 6: Operator-Specific Behaviors

#### String Operators (==, !=, contains)
- **Case-sensitive**: "John" != "john"
- **Exact matching**: == requires full field match
- **Substring matching**: contains finds substring anywhere in field

#### Numeric Operators (>, <, >=, <=)
- **Type coercion**: Attempts `Number()` conversion
- **Non-numeric handling**: Treated as false comparison
- **Float support**: Handles decimal values

---

### Flow 7: Reset / New File Upload

**Actor**: Any User  
**Precondition**: User has already uploaded and filtered a file

```
[User Uploads New File]
  ↓
hos[Old Data Cleared]
  ↓
[New File Parsed]
  ↓
[Filter Section Reset]
  ├─→ Column dropdown repopulated
  ├─→ Operator reset to first option
  ├─→ Value input cleared
  └─→ Error messages cleared
  ↓
[Results Section Hidden]
  ↓
[Ready for New Filter]
  ↓
END
```

---

## Edge Cases & Error Scenarios

### E1: Very Large Files (>10MB)
- **Behavior**: Browser may slow or warn; processing continues
- **UI Feedback**: Consider file size display (derived: Entry 12 in Style Decisions Log)

### E2: CSV with Inconsistent Column Counts
- **Behavior**: Rows with insufficient columns skipped during filtering
- **UI Feedback**: No special message (matches CLI silent skip)

### E3: Special Characters / Unicode
- **Behavior**: Handled by JavaScript string operations
- **UI Feedback**: Displayed correctly in results

### E4: Quoted Fields with Commas
- **Behavior**: Parsed correctly (quote-aware parsing)
- **UI Feedback**: Displayed correctly in results

### E5: Empty Rows in CSV
- **Behavior**: Skipped during parsing (matches CLI)
- **UI Feedback**: No indication of skipped rows

### E6: Multiple Filter Applications
- **Behavior**: Each "APPLY" replaces previous results
- **UI Feedback**: Results section updates in place

---

## State Machine

### Application States

```
STATE_EMPTY
  ├─→ [File Uploaded Successfully]
  │     └─→ STATE_FILE_LOADED
  │
  └─→ [File Upload Failed]
        └─→ STATE_ERROR (with error message)

STATE_FILE_LOADED
  ├─→ [Filter Applied Successfully]
  │     └─→ STATE_RESULTS_DISPLAYED
  │
  ├─→ [Filter Applied with Empty Results]
  │     └─→ rév STATE_RESULTS_EMPTY (header only)
  │
  └─→ [Filter Validation Failed]
        └─→ STATE_ERROR (with error message)

STATE_RESULTS_DISPLAYED
  ├─→ [New File Uploaded]
  │     └─→ STATE_FILE_LOADED (reset)
  │
  ├─→ [Filter Reapplied]
  │     └─→ STATE_RESULTS_DISPLAYED (updated)
  │
  └─→ [Export Clicked]
        └─→ STATE_RESULTS_DISPLAYED (no state change, download triggered)

STATE_RESULTS_EMPTY
  └─→ [Same as STATE_RESULTS_DISPLAYED transitions]

STATE_ERROR
  ├─→ [New File Uploaded]
  │     └─→ STATE_FILE_LOADED (error cleared)
  │
  └─→ [Filter Reapplied Correctly]
        └─→ STATE_RESULTS_DISPLAYED (error cleared)
```

---

**Document Version**: 1.0  
**Last Updated**: Initial creation  
**Maintainer**: UI/UX System Specification

