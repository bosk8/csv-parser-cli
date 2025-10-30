#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdexcept>
#include "csv_parser.hpp"
#include "filter_condition.hpp"

struct CLIArgs {
    std::string inputFile;
    size_t columnIndex;
    FilterOperator op;
    std::string filterValue;
    std::string outputFile;
    bool helpRequested;
};

class CLIParser {
public:
    static CLIArgs parseArgs(int argc, char* argv[]) {
        CLIArgs args;
        args.helpRequested = false;
        
        if (argc < 5) {
            if (argc == 2 && std::string(argv[1]) == "--help") {
                args.helpRequested = true;
                return args;
            }
            throw std::invalid_argument("Insufficient arguments");
        }
        
        args.inputFile = argv[1];
        
        try {
            args.columnIndex = std::stoul(argv[2]);
        } catch (const std::exception&) {
            throw std::invalid_argument("Invalid column index");
        }
        
        args.op = parseOperator(argv[3]);
        args.filterValue = argv[4];
        
        // Optional output file
        if (argc > 5) {
            args.outputFile = argv[5];
        }
        
        return args;
    }
    
    static void printUsage() {
        std::cout << "CSV Parser CLI - Filter CSV files by column conditions\n\n";
        std::cout << "Usage: csv_parser <input_file> <column_index> <operator> <value> [output_file]\n\n";
        std::cout << "Arguments:\n";
        std::cout << "  input_file   Path to CSV file to parse\n";
        std::cout << "  column_index Zero-based index of column to filter (0, 1, 2, ...)\n";
        std::cout << "  operator     Filter operator: ==, !=, >, <, >=, <=, contains\n";
        std::cout << "  value        Value to compare against\n";
        std::cout << "  output_file  Optional output file (default: stdout)\n\n";
        std::cout << "Examples:\n";
        std::cout << "  csv_parser data.csv 0 == \"John\"\n";
        std::cout << "  csv_parser data.csv 2 > 100\n";
        std::cout << "  csv_parser data.csv 1 contains \"Smith\" output.txt\n";
    }

private:
    static FilterOperator parseOperator(const std::string& opStr) {
        if (opStr == "==") return FilterOperator::EQUALS;
        if (opStr == "!=") return FilterOperator::NOT_EQUALS;
        if (opStr == ">") return FilterOperator::GREATER_THAN;
        if (opStr == "<") return FilterOperator::LESS_THAN;
        if (opStr == ">=") return FilterOperator::GREATER_EQUAL;
        if (opStr == "<=") return FilterOperator::LESS_EQUAL;
        if (opStr == "contains") return FilterOperator::CONTAINS;
        
        throw std::invalid_argument("Invalid operator: " + opStr);
    }
};

void outputResults(const std::vector<std::vector<std::string>>& data,
                  const std::vector<size_t>& matchingRows,
                  const std::string& outputFile) {
    
    std::ostream* out = &std::cout;
    std::ofstream file;
    
    if (!outputFile.empty()) {
        file.open(outputFile);
        if (!file.is_open()) {
            std::cerr << "Error: Cannot open output file '" << outputFile << "'\n";
            return;
        }
        out = &file;
    }
    
    // Output header row
    if (!data.empty()) {
        for (size_t i = 0; i < data[0].size(); ++i) {
            if (i > 0) *out << ",";
            *out << data[0][i];
        }
        *out << "\n";
    }
    
    // Output matching rows
    for (size_t rowIndex : matchingRows) {
        if (rowIndex < data.size()) {
            for (size_t i = 0; i < data[rowIndex].size(); ++i) {
                if (i > 0) *out << ",";
                *out << data[rowIndex][i];
            }
            *out << "\n";
        }
    }
    
    if (!outputFile.empty()) {
        file.close();
    }
}

int main(int argc, char* argv[]) {
    try {
        CLIArgs args = CLIParser::parseArgs(argc, argv);
        
        if (args.helpRequested) {
            CLIParser::printUsage();
            return 0;
        }
        
        // Validate input file exists
        std::ifstream testFile(args.inputFile);
        if (!testFile.is_open()) {
            std::cerr << "Error: Cannot open input file '" << args.inputFile << "'\n";
            return 1;
        }
        testFile.close();
        
        // Parse CSV file
        CSVParser parser;
        if (!parser.parse(args.inputFile)) {
            std::cerr << "Error: Failed to parse CSV file '" << args.inputFile << "'\n";
            return 1;
        }
        
        // Validate column index
        if (args.columnIndex >= parser.getColumnCount()) {
            std::cerr << "Error: Column index " << args.columnIndex 
                      << " exceeds available columns (" << parser.getColumnCount() << ")\n";
            return 1;
        }
        
        // Apply filter
        FilterCondition condition(args.columnIndex, args.op, args.filterValue);
        std::vector<size_t> matchingRows = CSVFilter::applyFilter(parser.getData(), condition);
        
        // Output results
        outputResults(parser.getData(), matchingRows, args.outputFile);
        
        return 0;
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n\n";
        CLIParser::printUsage();
        return 1;
    }
}
