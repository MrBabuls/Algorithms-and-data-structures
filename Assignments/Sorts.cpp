// Sources
// https://www.geeksforgeeks.org/dsa/shell-sort/
// https://www.geeksforgeeks.org/dsa/merge-sort/

#include "Sorts.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>
#include <iomanip>

using namespace std;

// ---------------- Shell Sort ----------------
void shellSort(vector<int>& arr) 
{
    int n = arr.size();
    for (int gap = n / 2; gap > 0; gap /= 2) 
    {
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) 
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

// ---------------- Merge Sort ----------------
void merge(vector<int>& arr, int left, int mid, int right) 
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) 
        L[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) 
    {
        if (L[i] <= R[j]) 
            arr[k++] = L[i++];
        else 
            arr[k++] = R[j++];
    }
    while 
        (i < n1) arr[k++] = L[i++];
    while 
        (j < n2) arr[k++] = R[j++];
}

void mergeSort(vector<int>& arr, int left, int right) 
{
    if (left < right) 
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// ---------------- Testing and execution times ----------------
vector<int> generateArray(int size, const string& type) 
{
    vector<int> arr(size);
    if (type == "random")
    {
        mt19937 rng(random_device{}());
        uniform_int_distribution<int> dist(0, size);
        for (int& x : arr) 
            x = dist(rng);
    }
    else if (type == "ascending") 
    {
        for (int i = 0; i < size; i++) 
            arr[i] = i;
    }
    else if (type == "descending") 
    {
        for (int i = 0; i < size; i++) 
            arr[i] = size - i;
    }
    return arr;
}

double measureTimeShell(vector<int>& arr) 
{
    auto start = chrono::high_resolution_clock::now();
    shellSort(arr);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    return elapsed.count();
}

double measureTimeMerge(vector<int>& arr) 
{
    auto start = chrono::high_resolution_clock::now();
    mergeSort(arr, 0, arr.size() - 1);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    return elapsed.count();
}

double measureTimeStd(vector<int>& arr) 
{
    auto start = chrono::high_resolution_clock::now();
    sort(arr.begin(), arr.end());
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    return elapsed.count();
}

// ---------------- Run Task 9 ----------------
void RunTask9() 
{
    vector<int> sizes = { 100, 10000, 100000 };
    vector<string> types = { "ascending", "descending", "random" };

    for (int size : sizes) 
    {
        for (const string& type : types) 
        {
            vector<int> arr = generateArray(size, type);
            vector<int> arrShell = arr;
            vector<int> arrMerge = arr;
            vector<int> arrStd = arr;

            double tShell = measureTimeShell(arrShell);
            double tMerge = measureTimeMerge(arrMerge);
            double tStd = measureTimeStd(arrStd);

            cout << fixed << setprecision(9);
            cout << "\nArray size: " << size << ", type: " << type << "\n";
            cout << "Shell sort: " << tShell << " s, per item: " << tShell / size << "\n";
            cout << "Merge sort: " << tMerge << " s, per item: " << tMerge / size << "\n";
            cout << "std::sort: " << tStd << " s, per item: " << tStd / size << "\n";
        }
    }
}