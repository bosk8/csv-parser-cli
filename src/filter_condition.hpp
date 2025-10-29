#ifndef FILTER_CONDITION_HPP
#define FILTER_CONDITION_HPP

#include <string>
#include <vector>
#include <cstddef>

enum class FilterOperator {
    EQUALS,           // ==
    NOT_EQUALS,       // !=
    GREATER_THAN,     // >
    LESS_THAN,        // <
    GREATER_EQUAL,    // >=
    LESS_EQUAL,       // <=
    CONTAINS          // contains
};

struct FilterCondition {
    size_t columnIndex;
    FilterOperator op;
    std::string value;
    
    FilterCondition(size_t col, FilterOperator op, const std::string& val)
        : columnIndex(col), op(op), value(val) {}
};

class CSVFilter {
public:
    // Apply filter to CSV data and return matching row indices
    static std::vector<size_t> applyFilter(
        const std::vector<std::vector<std::string>>& data,
        const FilterCondition& condition) {
        
        std::vector<size_t> matchingRows;
        
        for (size_t i = 0; i < data.size(); ++i) {
            if (condition.columnIndex >= data[i].size()) {
                continue; // Skip rows with insufficient columns
            }
            
            const std::string& cellValue = data[i][condition.columnIndex];
            
            if (evaluateCondition(cellValue, condition)) {
                matchingRows.push_back(i);
            }
        }
        
        return matchingRows;
    }
    
private:
    static bool evaluateCondition(const std::string& cellValue, const FilterCondition& condition) {
        switch (condition.op) {
            case FilterOperator::EQUALS:
                return cellValue == condition.value;
                
            case FilterOperator::NOT_EQUALS:
                return cellValue != condition.value;
                
            case FilterOperator::CONTAINS:
                return cellValue.find(condition.value) != std::string::npos;
                
            case FilterOperator::GREATER_THAN:
            case FilterOperator::LESS_THAN:
            case FilterOperator::GREATER_EQUAL:
            case FilterOperator::LESS_EQUAL:
                return evaluateNumericCondition(cellValue, condition);
                
            default:
                return false;
        }
    }
    
    // Helper to trim leading/trailing whitespace
    static std::string trim(const std::string& str) {
        const std::string whitespace = " \t\n\r";
        const auto strBegin = str.find_first_not_of(whitespace);
        if (strBegin == std::string::npos) return ""; // no content

        const auto strEnd = str.find_last_not_of(whitespace);
        const auto strRange = strEnd - strBegin + 1;

        return str.substr(strBegin, strRange);
    }

    static bool isNumber(const std::string& s) {
        try {
            std::stod(s);
        } catch(const std::invalid_argument&) {
            return false;
        } catch(const std::out_of_range&) {
            return false;
        }
        return true;
    }

    static bool evaluateNumericCondition(const std::string& cellValue, const FilterCondition& condition) {
        std::string trimmedCell = trim(cellValue);
        if (!isNumber(trimmedCell) || !isNumber(condition.value)) {
            return false; // Non-numeric values cannot satisfy numeric conditions
        }

        try {
            double cellNum = std::stod(trimmedCell);
            double conditionNum = std::stod(condition.value);
            
            switch (condition.op) {
                case FilterOperator::GREATER_THAN: return cellNum > conditionNum;
                case FilterOperator::LESS_THAN: return cellNum < conditionNum;
                case FilterOperator::GREATER_EQUAL: return cellNum >= conditionNum;
                case FilterOperator::LESS_EQUAL: return cellNum <= conditionNum;
                default: return false;
            }
        } catch (const std::exception&) {
            return false; // Should not be reached due to isNumber checks
        }
    }
};

#endif // FILTER_CONDITION_HPP
