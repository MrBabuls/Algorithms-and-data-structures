#include "Stack.h"
#include <iostream>
using namespace std;

Stack::Stack() : pTop(nullptr) {}

Stack::~Stack() {
    while (!IsEmpty()) {
        Pop();
    }
}

void Stack::Push(int value) {
    Node* pNewNode = new Node(value);
    pNewNode->next = pTop;
    pTop = pNewNode;
    cout << "Pushed: " << value << endl;
}

int Stack::Pop() {
    if (IsEmpty()) {
        throw runtime_error("Stack is empty.");
    }
    Node* pNodeToDelete = pTop;
    int value = pTop->data;
    pTop = pNodeToDelete->next;
    delete pNodeToDelete;
    return value;
}

bool Stack::IsEmpty() {
    return pTop == nullptr;
}

void Stack::Print() const {
    cout << "Stack contents: ";
    Node* temp = pTop;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void Stack::FillStack() {
    for (int i = 1; i <= 10; i++) {
        Push(i);
    }
}