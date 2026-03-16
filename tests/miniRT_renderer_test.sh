#!/bin/bash

# Configuration
BINARY="../miniRT"		# Path to your binary executable
RT_MISC="rt_misc"
RT_EXTREME="rt_extreme_renders"

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
    local test_name=$(basename "$input_file")
    echo -e "${GREEN}Running: ${NC}$test_name"
    "$BINARY" "$1"
    total_tests=$((total_tests + 1))
}

# Main script
echo -e "${BOLD}======================================${NC}"
echo -e "${BOLD}  miniRT Renderer Test Suite${NC}"
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

# Test miscellaneous scenes
echo -e "${YELLOW}Testing miscellaneous scenes...${NC}"
echo ""
if [ -d "$RT_MISC" ]; then
    if [ -n "$(ls -A "$RT_MISC" 2>/dev/null)" ]; then
        for input_file in "$RT_MISC"/*; do
            if [ -f "$input_file" ]; then
                run_test "$input_file" false
            fi
        done
    else
        echo -e "${YELLOW}  (No test files found in $RT_MISC)${NC}"
    fi
else
    echo -e "${YELLOW}  (Directory $RT_MISC not found)${NC}"
fi

echo ""

# Test extreme scenes
echo -e "${YELLOW}Testing extreme scenes...${NC}"
echo ""
if [ -d "$RT_EXTREME" ]; then
    if [ -n "$(ls -A "$RT_EXTREME" 2>/dev/null)" ]; then
        for input_file in "$RT_EXTREME"/*; do
            if [ -f "$input_file" ]; then
                run_test "$input_file" false
            fi
        done
    else
        echo -e "${YELLOW}  (No test files found in $RT_EXTREME)${NC}"
    fi
else
    echo -e "${YELLOW}  (Directory $RT_EXTREME not found)${NC}"
fi

echo ""

if [ $total_tests -eq 0 ]; then
    echo -e "${YELLOW}No tests were run!${NC}"
    exit 1
else
    echo -e "${GREEN}${BOLD}$total_tests tests were run!${NC}"
    exit 1
fi
