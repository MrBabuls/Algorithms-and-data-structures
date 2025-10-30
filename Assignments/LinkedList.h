#pragma once
#include "Node.h"

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