#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include <iostream>
using namespace std;

bool checkPrefixNonNegative(const int data[], int length) {
    int runningSum = 0;
    for (int i = 0; i < length; ++i) {
        runningSum += data[i];
        if (runningSum < 0) return false;
    }
    return true;
}

bool checkPrefixNonPositive(const int data[], int length) {
    int runningSum = 0;
    for (int i = 0; i < length; ++i) {
        runningSum += data[i];
        if (runningSum > 0) return false;
    }
    return true;
}

TEST_CASE("Case 1: Alternating array starting with +1") {
    int arr[] = {1, -1, 1, -1};
    CHECK(checkPrefixNonNegative(arr, 4) == true);
    CHECK(checkPrefixNonPositive(arr, 4) == false);
}

TEST_CASE("Case 2: Array that goes negative") {
    int arr[] = {1, -1, -1, 1};
    CHECK(checkPrefixNonNegative(arr, 4) == false);
    CHECK(checkPrefixNonPositive(arr, 4) == false);
}

TEST_CASE("Case 3: Array valid for non-positive prefix") {
    int arr[] = {-1, 1, -1, 1};
    CHECK(checkPrefixNonNegative(arr, 4) == false);
    CHECK(checkPrefixNonPositive(arr, 4) == true);
}

TEST_CASE("Case 4: Array with all -1 values") {
    int arr[] = {-1, -1, -1, -1};
    CHECK(checkPrefixNonNegative(arr, 4) == false);
    CHECK(checkPrefixNonPositive(arr, 4) == true);
}

TEST_CASE("Case 5: Array with all +1 values") {
    int arr[] = {1, 1, 1, 1};
    CHECK(checkPrefixNonNegative(arr, 4) == true);
    CHECK(checkPrefixNonPositive(arr, 4) == false);
}

int main(int argc, char** argv) {
    doctest::Context context;
    context.applyCommandLine(argc, argv);
    int testResult = context.run();
    if (context.shouldExit()) return testResult;
    int arraySize;
    cout << "\nEnter the number of elements for the array: ";
    cin >> arraySize;
    if (arraySize <= 0) {
        cout << "Error: Array size must be a positive integer." << endl;
        return 1;
    }
    int* arr = new int[arraySize];
    cout << "Enter " << arraySize << " numbers (each should be either +1 or -1):" << endl;
    for (int i = 0; i < arraySize; ++i) {
        cin >> arr[i];
    }
    bool nonNeg = checkPrefixNonNegative(arr, arraySize);
    bool nonPos = checkPrefixNonPositive(arr, arraySize);
    cout << "\nResults:" << endl;
    cout << "The Prefix sums doesn't go below zero: " << (nonNeg ? "this is true" : "this is false") << endl;
    cout << "The Prefix sums doesn't go above zero: " << (nonPos ? "this is true" : " this is false") << endl;
    delete[] arr;
    return testResult;
}