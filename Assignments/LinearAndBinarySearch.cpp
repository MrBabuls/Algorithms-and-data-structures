#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <chrono>

int linearSearch(int* array, int n, int x)
{
    // Iterate through the array from start to end
    for (int i = 0; i < n; i++)
    {
        // If the element matches x, return its index
        if (array[i] == x)
        {
            return i;
        }
    }

    // If the element was not found, return -1
    return -1;
}

int binarySearch(int* array, int n, int x)
{
    int start = 0;
    int end = n - 1;

    // Repeat until the search space is empty
    while (start <= end)
    {
        int mid = (start + end) / 2;

        // If the element at mid matches x, return its index
        if (array[mid] == x)
        {
            return mid;
        }
        // If the element at mid is smaller, search the right half
        else if (array[mid] < x)
        {
            start = mid + 1;
        }
        // Otherwise, search the left half
        else
        {
            end = mid - 1;
        }
    }

    return -1;
}

void measurePerformance(const std::vector<int>& sizes, int repeats)
{
    using namespace std::chrono;

    std::cout << "\n--- Performance measurement for linear and binary search ---" << std::endl;

    for (int n : sizes)
    {
        std::vector<int> array(n);

        for (int i = 0; i < n; i++)
        {
            array[i] = i;
        }

        int target = rand() % n;

        // Linear search timing
        auto start = high_resolution_clock::now();
        for (int i = 0; i < repeats; i++)
        {
            linearSearch(array.data(), n, target);
        }
        auto end = high_resolution_clock::now();
        auto linearTime = duration_cast<microseconds>(end - start).count();

        // Binary search timing
        start = high_resolution_clock::now();
        for (int i = 0; i < repeats; i++)
        {
            binarySearch(array.data(), n, target);
        }
        end = high_resolution_clock::now();
        auto binaryTime = duration_cast<microseconds>(end - start).count();

        std::cout << "\nArray size: " << n << std::endl;
        std::cout << "Linear search average time: " << (double)linearTime / repeats << " ms" << std::endl;
        std::cout << "Binary search average time: " << (double)binaryTime / repeats << " ms" << std::endl;
    }
}

void printArrayContents(int* array, int n)
{
    std::cout << "Print array contents" << std::endl;
    std::cout << "-------------------" << std::endl;
    for (int i = 0; i < n; i++)
    {
        std::cout << "| array[" << std::setw(2) << i << "] "
            << std::setw(5) << array[i] << " |" << std::endl;
    }
    std::cout << "-------------------" << std::endl;
    std::cout << std::endl;
}

int main()
{
    const int size = 20;
    int* array = new int[size];

    // Initialize array with values 0 to 19
    for (int i = 0; i < size; i++)
    {
        array[i] = i;
    }

    printArrayContents(array, size);

    // Number to search for
    int x = 12;
    std::cout << "Search for " << x << " in the array." << std::endl;
    std::cout << "" << std::endl;

    // Linear search
    int indexLinear = linearSearch(array, size, x);
    if (indexLinear != -1)
        std::cout << "Linear search: number found at index " << indexLinear << std::endl;
    else
        std::cout << "Linear search: number not found" << std::endl;

    // Binary search
    int indexBinary = binarySearch(array, size, x);
    if (indexBinary != -1)
        std::cout << "Binary search: number found at index " << indexBinary << std::endl;
    else
        std::cout << "Binary search: number not found" << std::endl;

    delete[] array; // Free allocated memory

    std::vector<int> testSizes = { 100000, 1000000, 10000000 };
    int repeats = 20;
    measurePerformance(testSizes, repeats);

    return 0;
}
