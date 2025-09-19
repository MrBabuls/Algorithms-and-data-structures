// Sources:  
// https://cplusplus.com/forum/beginner/152180/
// https://www.geeksforgeeks.org/dsa/ackermann-function/
#include "FibonacciAndAckermann.h"
#include <iostream>
#include <cstdlib>

using namespace std;

// Iterative Fibonacci using array
long long fib_iterative(int n) 
{
    if (n <= 1)
    {
        return n;
    }

    long long* array = new long long[n + 1];
    array[0] = 0;
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

    long long a = 0, b = 1;
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
    long long fib1 = fib_iterative(n);
    cout << "Fibonacci number f(" << n << ") = " << fib1 << "\n";
    cout << "Memory used: " << (n + 1) * sizeof(long long) << " bytes\n\n";

    cout << "--- Optimized Fibonacci ---\n";
    long long fib2 = fib_optimized(n);
    cout << "Fibonacci number f(" << n << ") = " << fib2 << "\n";
    cout << "Memory used: " << 2 * sizeof(long long) << " bytes\n\n";
}

unsigned long long Ackermann(unsigned int m, unsigned int n)
{
    if (m == 0)
        return n + 1;
    else if (n == 0)
        return Ackermann(m - 1, 1);
    else
        return Ackermann(m - 1, Ackermann(m, n - 1));
}

void RunAckermann()
{
    cout << "Programming task 3.2. Compute Ackermann function.\n\n";

    unsigned int m = 2, n = 2;
    cout << "Ackermann A(" << m << "," << n << ") = " << Ackermann(m, n) << "\n";

    m = 2; n = 3;
    cout << "Ackermann A(" << m << "," << n << ") = " << Ackermann(m, n) << "\n";

    m = 3; n = 2;
    cout << "Ackermann A(" << m << "," << n << ") = " << Ackermann(m, n) << "\n";

    m = 3; n = 4;
    cout << "Ackermann A(" << m << "," << n << ") = " << Ackermann(m, n) << "\n";
}
