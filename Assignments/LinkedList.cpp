#include "LinkedList.h"
#include <iostream>
using namespace std;

// Node implementation
Node::Node(int value) 
{
    data = value;
    next = nullptr;
}

// LinkedList constructor
LinkedList::LinkedList() 
{
    head = new Node(0);
    head->next = nullptr;
}

// LinkedList destructor
LinkedList::~LinkedList() 
{
    Node* current = head;
    while (current) 
    {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

// Task 5.1 Methods
bool LinkedList::IsEmpty() 
{
    return head->next == nullptr;
}

void LinkedList::Insert(int value) 
{
    Node* n = new Node(value);
    n->next = head->next;
    head->next = n;
}

void LinkedList::InsertEnd(int value) 
{
    Node* n = new Node(value);
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = n;
}

void LinkedList::Print() 
{
    Node* temp = head->next;
    while (temp) 
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Task 5.1 Function
void LinkedList::testTask5_1() 
{
    cout << "=== Task 5.1: Linked List Operations ===" << endl;

    // Insert at beginning
    for (int i = 1; i <= 10; i++)
        Insert(i);
    cout << "After Insert(1-10): ";
    Print();

    // Insert at end
    LinkedList list2;
    for (int i = 1; i <= 10; i++)
        list2.InsertEnd(i);
    cout << "After InsertEnd(1-10): ";
    list2.Print();

    cout << "IsEmpty() for first list: " << (IsEmpty() ? "Yes" : "No") << endl;
}
