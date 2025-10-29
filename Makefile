# Makefile for CSV Parser CLI

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2
TARGET = bin/csv_parser
SRCDIR = src
SOURCES = $(SRCDIR)/main.cpp $(SRCDIR)/csv_parser.cpp
OBJECTS = $(SOURCES:.cpp=.o)

.PHONY: all build clean run test help

all: build

build: $(TARGET)

$(TARGET): $(OBJECTS)
	@mkdir -p bin
	$(CXX) $(OBJECTS) -o $(TARGET)

$(SRCDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)
	rm -rf bin

run: build
	@echo "Running CSV Parser with sample data..."
	@if [ -f data/sample.csv ]; then \
		/lib64/ld-linux-x86-64.so.2 ./$(TARGET) data/sample.csv 0 == "John"; \
	else \
		echo "Sample data not found. Please create data/sample.csv first."; \
	fi

test: build
	@echo "Running basic tests..."
	@echo "Test 1: Basic filtering"
	@if [ -f data/sample.csv ]; then \
		/lib64/ld-linux-x86-64.so.2 ./$(TARGET) data/sample.csv 0 == "John" > /tmp/test1.out && echo "✓ Test 1 passed"; \
	else \
		echo "✗ Test 1 failed: data/sample.csv not found"; \
	fi
	@echo "Test 2: Help message"
	@/lib64/ld-linux-x86-64.so.2 ./$(TARGET) --help > /tmp/test2.out && echo "✓ Test 2 passed" || echo "✗ Test 2 failed"
	@echo "Test 3: Numeric comparison"
	@if [ -f data/sample.csv ]; then \
		/lib64/ld-linux-x86-64.so.2 ./$(TARGET) data/sample.csv 1 ">" 25 > /tmp/test3.out && echo "✓ Test 3 passed"; \
	else \
		echo "✗ Test 3 failed: data/sample.csv not found"; \
	fi

help:
	@echo "Available targets:"
	@echo "  build  - Compile the CSV parser"
	@echo "  clean  - Remove build artifacts"
	@echo "  run    - Run with sample data"
	@echo "  test   - Run basic tests"
	@echo "  help   - Show this help message"
