#include"Heap.h"
#include <vector>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;
using namespace std::chrono;

Heap::Heap()
{
	for (int i = 0; i <= MAX_HEAP_SIZE; i++)
	{
		heapArray[i] = 0;
	}
}

bool Heap::insert(int value)
{
    int heapSize = heapArray[0];
    if (heapSize < MAX_HEAP_SIZE) 
    {
        heapArray[heapSize + 1] = value;
        int currentIndex = heapSize + 1;
        int parentIndex = currentIndex / 2;

        while (currentIndex > 1 && heapArray[parentIndex] > value) 
        {
            heapArray[currentIndex] = heapArray[parentIndex];
            heapArray[parentIndex] = value;
            currentIndex = parentIndex;
            parentIndex = currentIndex / 2;
        }

        heapArray[0]++; // Increase heap size
        return true;
    }
    return false; // Heap full
}

// Delete minimum element (root) from min-heap
int Heap::delMin() 
{
    int heapSize = heapArray[0];
    if (heapSize == 0) 
    {
        cout << "Heap is empty!" << endl;
        return -1; // or throw exception
    }

    int minValue = heapArray[1]; // root
    int lastValue = heapArray[heapSize];
    heapArray[0]--; // decrease size
    heapArray[1] = lastValue;

    // Heapify down
    int currentIndex = 1;
    while (true) 
    {
        int left = 2 * currentIndex;
        int right = 2 * currentIndex + 1;
        int smallest = currentIndex;

        if (left <= heapArray[0] && heapArray[left] < heapArray[smallest])
            smallest = left;
        if (right <= heapArray[0] && heapArray[right] < heapArray[smallest])
            smallest = right;

        if (smallest != currentIndex) 
        {
            swap(heapArray[currentIndex], heapArray[smallest]);
            currentIndex = smallest;
        }
        else 
        {
            break;
        }
    }

    return minValue;
}

// Print heap contents
void Heap::print() 
{
    cout << "Heap size: " << heapArray[0] << endl;
    cout << "[";
    for (int i = 1; i <= heapArray[0]; i++) 
    {
        cout << heapArray[i];
        if (i != heapArray[0]) cout << ",";
    }
    cout << "]" << endl;
}

void Heap::runHeapSortSpeedTest()
{
    cout << "\n--- Programming Task 7.2: Heap Sort Speed ---\n";

    // Eri testikoot
    vector<int> sizes = { 100000, 1000000, 10000000 };

    for (int n : sizes) {
        cout << "\nCreating array with " << n << " random integers..." << endl;

        vector<int> data;
        data.reserve(n);
        srand((unsigned)time(0));

        for (int i = 0; i < n; i++) {
            data.push_back(rand());
        }

        cout << "Sorting..." << endl;

        // Aloita ajanotto
        auto start = high_resolution_clock::now();

        // Tee heapsort vektorilla
        // 1. Luo heap
        vector<int> heap;
        heap.push_back(0); // indeksi 0 varattu koolle
        int heapSize = 0;

        // Insert kaikki dataan
        for (int value : data) {
            heapSize++;
            if (heapSize >= (int)heap.size())
                heap.push_back(value);
            else
                heap[heapSize] = value;

            int current = heapSize;
            int parent = current / 2;
            while (current > 1 && heap[parent] > heap[current]) {
                swap(heap[parent], heap[current]);
                current = parent;
                parent = current / 2;
            }
        }

        // 2. Poista kaikki delMin()-periaatteella
        vector<int> sorted;
        sorted.reserve(n);

        while (heapSize > 0) {
            int minValue = heap[1];
            sorted.push_back(minValue);
            heap[1] = heap[heapSize];
            heapSize--;

            int current = 1;
            while (true) {
                int left = 2 * current;
                int right = 2 * current + 1;
                int smallest = current;

                if (left <= heapSize && heap[left] < heap[smallest])
                    smallest = left;
                if (right <= heapSize && heap[right] < heap[smallest])
                    smallest = right;

                if (smallest != current) {
                    swap(heap[current], heap[smallest]);
                    current = smallest;
                }
                else {
                    break;
                }
            }
        }

        // Lopeta ajanotto
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(end - start).count();

        cout << "Time used: " << duration << " ms" << endl;
    }

    cout << "\nHeap sort complexity: O(n log n)" << endl;
}