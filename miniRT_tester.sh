#!/bin/bash

# Configuration
BINARY="./miniRT"		# Path to your binary executable
SUCCESS_DIR="tests/rt_valid"	# Directory with files that should succeed
ERROR_DIR="tests/rt_invalid"	# Directory with files that should produce errors

# Color codes
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color
BOLD='\033[1m'

# Counters
total_tests=0
passed_tests=0
failed_tests=0

# Function to run a single test
run_test() {
    local input_file="$1"
    local should_error="$2"
    local test_name=$(basename "$input_file")
    
    total_tests=$((total_tests + 1))
    
    # Run the binary and capture stderr
    stderr_output=$(mktemp)
    "$BINARY" "$input_file" 2>"$stderr_output" >/dev/null
    exit_code=$?
    
    # Check if "Error" (with or without \n) is in stderr
    if grep -q "Error" "$stderr_output"; then
        has_error=true
    else
        has_error=false
    fi
    
    # Determine if test passed
    if [ "$should_error" = true ]; then
        # This test should produce an error
        if [ "$has_error" = true ]; then
            echo -e "${GREEN}✓ PASS${NC} ${BLUE}$test_name${NC} - Error correctly produced"
            passed_tests=$((passed_tests + 1))
        else
            echo -e "${RED}✗ FAIL${NC} ${BLUE}$test_name${NC} - Expected error but got none"
            failed_tests=$((failed_tests + 1))
        fi
    else
        # This test should NOT produce an error
        if [ "$has_error" = false ]; then
            echo -e "${GREEN}✓ PASS${NC} ${BLUE}$test_name${NC} - No error (as expected)"
            passed_tests=$((passed_tests + 1))
        else
            echo -e "${RED}✗ FAIL${NC} ${BLUE}$test_name${NC} - Unexpected error produced"
            failed_tests=$((failed_tests + 1))
        fi
    fi
    
    # Clean up
    rm -f "$stderr_output"
}

# Main script
echo -e "${BOLD}======================================${NC}"
echo -e "${BOLD}  miniRT Test Suite${NC}"
echo -e "${BOLD}======================================${NC}"
echo ""

# Check if binary exists
if [ ! -f "$BINARY" ]; then
    echo -e "${RED}Error: Binary '$BINARY' not found!${NC}"
    exit 1
fi

# Check if binary is executable
if [ ! -x "$BINARY" ]; then
    echo -e "${RED}Error: Binary '$BINARY' is not executable!${NC}"
    exit 1
fi

# Test files that should succeed
echo -e "${YELLOW}Testing files that should succeed...${NC}"
echo ""
if [ -d "$SUCCESS_DIR" ]; then
    if [ -n "$(ls -A "$SUCCESS_DIR" 2>/dev/null)" ]; then
        for input_file in "$SUCCESS_DIR"/*; do
            if [ -f "$input_file" ]; then
                run_test "$input_file" false
            fi
        done
    else
        echo -e "${YELLOW}  (No test files found in $SUCCESS_DIR)${NC}"
    fi
else
    echo -e "${YELLOW}  (Directory $SUCCESS_DIR not found)${NC}"
fi

echo ""

# Test files that should produce errors
echo -e "${YELLOW}Testing files that should produce errors...${NC}"
echo ""
if [ -d "$ERROR_DIR" ]; then
    if [ -n "$(ls -A "$ERROR_DIR" 2>/dev/null)" ]; then
        for input_file in "$ERROR_DIR"/*; do
            if [ -f "$input_file" ]; then
                run_test "$input_file" true
            fi
        done
    else
        echo -e "${YELLOW}  (No test files found in $ERROR_DIR)${NC}"
    fi
else
    echo -e "${YELLOW}  (Directory $ERROR_DIR not found)${NC}"
fi

# Summary
echo ""
echo -e "${BOLD}======================================${NC}"
echo -e "${BOLD}  Test Summary${NC}"
echo -e "${BOLD}======================================${NC}"
echo -e "Total tests:  ${BOLD}$total_tests${NC}"
echo -e "Passed:       ${GREEN}${BOLD}$passed_tests${NC}"
echo -e "Failed:       ${RED}${BOLD}$failed_tests${NC}"
echo ""

if [ $failed_tests -eq 0 ] && [ $total_tests -gt 0 ]; then
    echo -e "${GREEN}${BOLD}All tests passed! 🎉${NC}"
    exit 0
elif [ $total_tests -eq 0 ]; then
    echo -e "${YELLOW}No tests were run!${NC}"
    exit 1
else
    echo -e "${RED}${BOLD}Some tests failed!${NC}"
    exit 1
fi
