#pragma once

class Node {
public:
	int data;
	Node* next;
	Node(int value);
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList();
    ~LinkedList();

    bool IsEmpty();
    void Insert(int value);
    void InsertEnd(int value);
    void Print();
    bool Find(int value);
    bool Delete(int value);
    void Reverse();
    
    void task5_1();
    void task5_2();
};