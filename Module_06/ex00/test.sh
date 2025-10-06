#!/bin/bash

# Test script for ScalarConverter

echo "=== Testing char literals ==="
./convert "'a'"
echo ""
./convert "'z'"
echo ""
./convert "'0'"
echo ""

echo "=== Testing int literals ==="
./convert "0"
echo ""
./convert "42"
echo ""
./convert "-42"
echo ""
./convert "127"
echo ""
./convert "2147483647"
echo ""

echo "=== Testing float literals ==="
./convert "0.0f"
echo ""
./convert "42.0f"
echo ""
./convert "4.2f"
echo ""
./convert "-4.2f"
echo ""

echo "=== Testing double literals ==="
./convert "0.0"
echo ""
./convert "42.0"
echo ""
./convert "4.2"
echo ""
./convert "-4.2"
echo ""

echo "=== Testing pseudo-literals ==="
./convert "nan"
echo ""
./convert "nanf"
echo ""
./convert "+inf"
echo ""
./convert "-inf"
echo ""
./convert "+inff"
echo ""
./convert "-inff"
echo ""

echo "=== Testing edge cases ==="
./convert "31"  # Non-displayable
echo ""
./convert "32"  # First displayable (space)
echo ""
./convert "126" # Last displayable (~)
echo ""
./convert "127" # DEL (non-displayable)
echo ""
./convert "128" # Outside ASCII range
echo ""

echo "=== Testing invalid input ==="
./convert "invalid"
echo ""
./convert "42.42.42"
echo ""
./convert ""
echo ""
