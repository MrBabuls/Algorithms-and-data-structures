#include"Heap.h"

#include <iostream>

using namespace std;

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