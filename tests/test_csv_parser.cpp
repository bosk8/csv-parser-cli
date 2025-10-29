#define CATCH_CONFIG_MAIN
#include <cstddef>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "catch.hpp"
#include "csv_parser.hpp"
#include "filter_condition.hpp"

TEST_CASE("CSVParser Core Functionality", "[CSVParser]") {
    CSVParser parser;
    // Create a dummy CSV file for testing
    std::ofstream testFile("test.csv");
    testFile << "Name,Age,City\n";
    testFile << "John,25,\"New York\"\n";
    testFile << "Jane,30,London\n";
    testFile << "\"Mr. Smith\",40,\"Los Angeles\"\n";
    testFile.close();

    SECTION("Parsing and Data Access") {
        REQUIRE(parser.parse("test.csv"));
        REQUIRE(parser.getRowCount() == 4);
        REQUIRE(parser.getColumnCount() == 3);
        REQUIRE(parser.getCell(1, 0) == "John");
        REQUIRE(parser.getCell(2, 2) == "London");
    }

    SECTION("Quoted Fields") {
        parser.parse("test.csv");
        REQUIRE(parser.getCell(1, 2) == "New York");
        REQUIRE(parser.getCell(3, 0) == "Mr. Smith");
        REQUIRE(parser.getCell(3, 2) == "Los Angeles");
    }

    // Clean up the dummy file
    remove("test.csv");
}

TEST_CASE("CSVFilter Functionality", "[CSVFilter]") {
    CSVParser parser;
    std::ofstream testFile("test_filter.csv");
    testFile << "Name,Value,Flag\n";
    testFile << "A,10,true\n";
    testFile << "B,20,false\n";
    testFile << "C,10,true\n";
    testFile.close();

    parser.parse("test_filter.csv");
    const auto& data = parser.getData();

    SECTION("Equals Operator") {
        FilterCondition condition(0, FilterOperator::EQUALS, "A");
        auto result = CSVFilter::applyFilter(data, condition);
        REQUIRE(result.size() == 1);
        REQUIRE(result[0] == 1);
    }

    SECTION("Numeric Comparison") {
        FilterCondition condition(1, FilterOperator::GREATER_THAN, "15");
        auto result = CSVFilter::applyFilter(data, condition);
        REQUIRE(result.size() == 1);
        REQUIRE(result[0] == 2);
    }

    // Clean up
    remove("test_filter.csv");
}

TEST_CASE("Mixed Data and Edge Cases", "[CSVParser]") {
    CSVParser parser;
    REQUIRE(parser.parse("data/mixed_data.csv"));

    const auto& data = parser.getData();

    SECTION("Handles various data types and formats") {
        REQUIRE(parser.getRowCount() == 9); // Including header
        REQUIRE(parser.getCell(1, 2) == " 100 "); // Preserves whitespace
        REQUIRE(parser.getCell(4, 2) == " 150.5 ");
    }

    SECTION("Filtering on mixed data") {
        // Test numeric comparison with whitespace
        FilterCondition condition(2, FilterOperator::GREATER_THAN, "150");
        auto result = CSVFilter::applyFilter(data, condition);
        REQUIRE(result.size() == 4);
        REQUIRE(result[0] == 2); // 250
        REQUIRE(result[1] == 4); // 150.5
        REQUIRE(result[2] == 5); // 300
        REQUIRE(result[3] == 8); // 200

        // Test filtering non-numeric data
        FilterCondition condition2(2, FilterOperator::EQUALS, " non-numeric ");
        result = CSVFilter::applyFilter(data, condition2);
        REQUIRE(result.size() == 1);
        REQUIRE(result[0] == 3);
    }
}
