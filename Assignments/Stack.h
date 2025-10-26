#pragma once
#include "Node.h"

class Stack {
private:
    Node* pTop;

public:
    Stack();
    ~Stack();

    void Push(int value);
    int Pop();
    bool IsEmpty();
    void Print() const;
    void FillStack();
};