#include "LinkedList.h"
#include <iostream>

using namespace std;

Node::Node(int value) { data = value; next = nullptr; }

LinkedList::LinkedList() { head = new Node(0); head->next = nullptr; }
LinkedList::~LinkedList() {
    Node* current = head;
    while (current) { Node* next = current->next; delete current; current = next; }
}

void LinkedList::testInit() {
    cout << "LinkedList initialized. IsEmpty(): " << (head->next == nullptr ? "Yes" : "No") << endl;
}