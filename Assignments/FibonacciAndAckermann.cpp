#include "FibonacciAndAckermann.h"
#include <iostream>
#include <cstdlib>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Iterative Fibonacci using array
long long fib_iterative(int n) 
{
    if (n <= 1)
    {
        return n;
    }

    long long* array = new long long[n + 1];
    array[0] = 1;
    array[1] = 1;

    for (int i = 2; i <= n; i++) 
    {
        array[i] = array[i - 1] + array[i - 2];
    }

    long long result = array[n];
    delete[] array;
    return result;
}

// Optimized iterative Fibonacci using only two variables
long long fib_optimized(int n) 
{
    if (n <= 1)
    {
        return n;
    }

    long long a = 1, b = 1;
    for (int i = 2; i <= n; i++) 
    {
        long long temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}

void RunFibonacci() 
{
    cout << "Programming task 3.1. Implement the algorithm for computing Fibonacci numbers iteratively.\n\n";

    int n = 20;

    cout << "--- Fibonacci using array ---\n";
    auto start1 = high_resolution_clock::now();
    long long fib1 = fib_iterative(n);
    auto end1 = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(end1 - start1).count();

    cout << "Fibonacci number f(" << n << ") = " << fib1 << "\n";
    cout << "Time taken: " << duration1 << " ms\n\n";

    cout << "--- Optimized Fibonacci ---\n";
    auto start2 = high_resolution_clock::now();
    long long fib2 = fib_optimized(n);
    auto end2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(end2 - start2).count();

    cout << "Fibonacci number f(" << n << ") = " << fib2 << "\n";
    cout << "Time taken: " << duration2 << " ms\n";
}
