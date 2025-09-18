#pragma once
#include <vector>

int linearSearch(int* array, int n, int x);
int binarySearch(int* array, int n, int x);
void measurePerformance(const std::vector<int>& sizes, int repeats);
void printArrayContents(int* array, int n);


void LinearAndBinarySearch();
