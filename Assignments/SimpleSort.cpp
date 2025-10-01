#include "SimpleSort.h"
#include <iostream>
#include <vector>
#include <random>
#include <chrono>

using namespace std;
using namespace std::chrono;

void simpleSort(vector<float>& arr) 
{
    int n = static_cast<int>(arr.size());
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) 
        {
            if (arr[j] < arr[i]) 
            {
                float tmp = arr[j];
                arr[j] = arr[i];
                arr[i] = tmp;
            }
        }
    }
}

void RunSimpleSort() 
{
    vector<size_t> sizes = { 100000, 1000000, 10000000 };

    for (size_t n : sizes) 
    {
        vector<float> arr(n);
        mt19937 gen(42);
        uniform_real_distribution<float> dist(0.0f, 1.0f);
        for (size_t i = 0; i < n; ++i) 
        {
            arr[i] = dist(gen);
        }

        cout << "Sorting " << n << " floats..." << endl;
        auto start = high_resolution_clock::now();
        simpleSort(arr);
        auto end = high_resolution_clock::now();

        double duration = duration_cast<std::chrono::duration<double>>(end - start).count();
        cout << "Time: " << duration << " seconds\n" << endl;
    }
}