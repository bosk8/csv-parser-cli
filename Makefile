# Makefile for CSV Parser CLI

# Makefile for CSV Parser CLI

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2
TARGET = bin/csv_parser
SRCDIR = src
TESTDIR = tests
SOURCES = $(SRCDIR)/main.cpp $(SRCDIR)/csv_parser.cpp
OBJECTS = $(SOURCES:.cpp=.o)
TEST_TARGET = bin/test_runner
TEST_SOURCES = $(TESTDIR)/test_csv_parser.cpp

.PHONY: all build clean run test help

all: build

build: $(TARGET)

$(TARGET): $(OBJECTS)
	@mkdir -p bin
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET)

$(SRCDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET) $(TEST_TARGET)
	rm -rf bin

run: build
	@echo "Running CSV Parser with sample data..."
	@if [ -f data/sample.csv ]; then \
		./$(TARGET) data/sample.csv 0 == "John"; \
	else \
		echo "Sample data not found. Please create data/sample.csv first."; \
	fi

test: $(TEST_TARGET)
	@echo "Running tests..."
	./$(TEST_TARGET)

$(TEST_TARGET): $(TEST_SOURCES) $(filter-out $(SRCDIR)/main.o,$(OBJECTS))
	@mkdir -p bin
	$(CXX) $(CXXFLAGS) -I$(SRCDIR) $^ -o $@

help:
	@echo "Available targets:"
	@echo "  build  - Compile the CSV parser"
	@echo "  clean  - Remove build artifacts"
	@echo "  run    - Run with sample data"
	@echo "  test   - Run tests"
	@echo "  help   - Show this help message"
