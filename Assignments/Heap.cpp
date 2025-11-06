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
    if (heapArray[0] < MAX_HEAP_SIZE)
    {
        // 1. Insert new value at the end 
        heapArray[heapSize + 1] = value;
        // 2. Lift the value up to correct spot 
        // - Stop when parent is smaller or we are at root 
        // <--> Continue currentIndex > 1 and 
        //      heapArray[parentIndex] > value; 
        int currentIndex = heapSize + 1;
        int parentIndex = currentIndex / 2;
        while (currentIndex > 1 &&
            heapArray[parentIndex] > value)
        {
            // Swap values and update indices
            heapArray[currentIndex] = heapArray[parentIndex];

            // Update value at parentIndex
            heapArray[parentIndex] = value;

            // Update indices
            currentIndex = parentIndex;
            parentIndex = currentIndex / 2;
        }
        // 3. Accumulate heap size 
        heapArray[0]++;
        return true;
    }
    else
        return false;
}


void Heap::print()
{
    cout << "Heap size: " << heapArray[0] << endl;
    cout << "[";
    for (int i = 1; i <= heapArray[0]; i++)
    {
        cout << heapArray[i] << ",";
    }
    cout << heapArray[heapArray[0]];
    cout << "]" << endl;
}