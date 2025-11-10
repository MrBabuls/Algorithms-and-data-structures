#pragma once
#define MAX_HEAP_SIZE 100

class Heap {
public: 
	Heap();
	~Heap() {}
	bool insert(int value);
	int delMin();
	void print();

	static Heap createSampleTree();

private:
	int heapArray[MAX_HEAP_SIZE + 1];
};