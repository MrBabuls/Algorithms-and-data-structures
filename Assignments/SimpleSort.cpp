#include "SimpleSort.h"
#include <iostream>
#include <vector>

using namespace std;

void simpleSort(vector<float>& arr) 
{
    int n = static_cast<int>(arr.size());
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (arr[j] < arr[i]) {
                float tmp = arr[j];
                arr[j] = arr[i];
                arr[i] = tmp;
            }
        }
    }
}

void RunSimpleSort() 
{
    vector<float> arr = { 0.5f, 0.2f, 0.9f, 0.1f, 0.7f };

    cout << "Before sorting:\n";
    for (float v : arr) cout << v << " ";
    cout << "\n";

    simpleSort(arr);

    cout << "After sorting:\n";
    for (float v : arr) cout << v << " ";
    cout << "\n";
}