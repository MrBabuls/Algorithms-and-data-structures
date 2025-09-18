#include "LinearAndBinarySearch.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <chrono>
#include <string>

using namespace std;

int linearSearch(int* array, int n, int x) {
    for (int i = 0; i < n; i++) {
        if (array[i] == x) return i;
    }
    return -1;
}

int binarySearch(int* array, int n, int x) {
    int start = 0, end = n - 1;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (array[mid] == x) return mid;
        else if (array[mid] < x) start = mid + 1;
        else end = mid - 1;
    }
    return -1;
}

void measurePerformance(const vector<int>& sizes, int repeats) {
    using namespace chrono;

    for (int n : sizes) {
        vector<int> array(n);
        for (int i = 0; i < n; i++) array[i] = i;
        int target = rand() % n;

        auto start = high_resolution_clock::now();
        for (int i = 0; i < repeats; i++) linearSearch(array.data(), n, target);
        auto end = high_resolution_clock::now();
        auto linearTime = duration_cast<microseconds>(end - start).count();

        start = high_resolution_clock::now();
        for (int i = 0; i < repeats; i++) binarySearch(array.data(), n, target);
        end = high_resolution_clock::now();
        auto binaryTime = duration_cast<microseconds>(end - start).count();

        cout << "Array size: " << n << "\n"
            << "Linear avg: " << (double)linearTime / repeats << " ms\n"
            << "Binary avg: " << (double)binaryTime / repeats << " ms\n\n";
    }
}

void printArrayContents(int* array, int n) {
    for (int i = 0; i < n; i++) {
        cout << "| array[" << setw(2) << i << "] "
            << setw(5) << array[i] << " |\n";
    }
    cout << endl;
}

void LinearAndBinarySearch() {
    const int size = 20;
    int* array = new int[size];
    for (int i = 0; i < size; i++) array[i] = i;

    cout << "Programming task 2.1. Implement the linear search and binary search.\n\n";

    printArrayContents(array, size);

    int x = 12;
    cout << "Search for " << x << " in the array.\n\n";

    int indexLinear = linearSearch(array, size, x);
    cout << "Linear search: "
        << (indexLinear != -1 ? "found at index " + to_string(indexLinear) : "not found")
        << endl;

    int indexBinary = binarySearch(array, size, x);
    cout << "Binary search: "
        << (indexBinary != -1 ? "found at index " + to_string(indexBinary) : "not found")
        << endl;

    cout << " " << endl;

    delete[] array;

    cout << "Programming task 2.2. Measure the performance of linear and binary search.\n\n";

    measurePerformance({ 100000, 1000000, 10000000 }, 20);
}
