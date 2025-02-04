# SamEmile3150Lab1

# Lab 1: Prefix Sum Checker

## Summary
This program checks whether the prefix sums of an array remain non-negative or non-positive. It also includes test cases using the Doctest framework to verify correctness.

## Requirements
- C++ compiler (supports C++17)
- Doctest framework (included in the code)

## How to Compile
```sh
g++ -std=c++17 samlab1.cpp -o samlab1
```

## How to Run
```sh
./samlab1
```

## Usage
- The program first runs test cases.
- Then, it prompts the user to enter an array size and values.
- It checks whether the prefix sums stay non-negative or non-positive.

## Example Run
```
Enter the number of elements for the array: 6
Enter 6 numbers (each should be either +1 or -1):
1
1
-1
-1
-1
-1

Results:
The Prefix sums doesn't go below zero: this is false
The Prefix sums doesn't go above zero: this is false
```

## Notes
- The array size must be a positive integer.
- Elements should only be +1 or -1.
- Doctest is used for testing (already included in the program).

