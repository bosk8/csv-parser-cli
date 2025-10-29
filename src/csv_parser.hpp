#ifndef CSV_PARSER_HPP
#define CSV_PARSER_HPP

#include <vector>
#include <string>
#include <fstream>
#include <sstream>

class CSVParser {
private:
    std::vector<std::vector<std::string>> data;
    
    // Helper function to parse a single CSV line with quote awareness
    std::vector<std::string> parseLine(const std::string& line) {
        std::vector<std::string> fields;
        std::stringstream ss(line);
        std::string field;
        bool inQuotes = false;
        
        while (ss.good()) {
            char c = ss.get();
            
            if (c == '"') {
                inQuotes = !inQuotes;
            } else if (c == ',' && !inQuotes) {
                fields.push_back(field);
                field.clear();
            } else if (c != EOF) {
                field += c;
            }
        }
        
        // Add the last field
        if (!field.empty() || ss.gcount() > 0) {
            fields.push_back(field);
        }
        
        return fields;
    }

public:
    // Parse CSV file and store data
    bool parse(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            return false;
        }
        
        data.clear();
        std::string line;
        
        while (std::getline(file, line)) {
            // Skip empty lines
            if (line.empty()) {
                continue;
            }
            
            std::vector<std::string> fields = parseLine(line);
            if (!fields.empty()) {
                data.push_back(fields);
            }
        }
        
        file.close();
        return true;
    }
    
    // Get the parsed data
    const std::vector<std::vector<std::string>>& getData() const {
        return data;
    }
    
    // Get number of rows
    size_t getRowCount() const {
        return data.size();
    }
    
    // Get number of columns (assumes all rows have same number of columns)
    size_t getColumnCount() const {
        return data.empty() ? 0 : data[0].size();
    }
    
    // Get a specific cell value
    std::string getCell(size_t row, size_t col) const {
        if (row >= data.size() || col >= data[row].size()) {
            return "";
        }
        return data[row][col];
    }
};

#endif // CSV_PARSER_HPP
