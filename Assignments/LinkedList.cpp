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
void LinkedList::task5_1() 
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

// Task 5.2 Methods
bool LinkedList::Find(int value) 
{
    Node* temp = head->next;
    while (temp) 
    {
        if (temp->data == value)
            return true;
        temp = temp->next;
    }
    return false;
}

bool LinkedList::Delete(int value) 
{
    Node* prev = head;
    Node* curr = head->next;
    while (curr) 
    {
        if (curr->data == value) 
        {
            prev->next = curr->next;
            delete curr;
            return true;
        }
        prev = curr;
        curr = curr->next;
    }
    return false;
}

void LinkedList::Reverse() 
{
    Node* prev = nullptr;
    Node* curr = head->next;
    Node* next = nullptr;
    while (curr) 
    {
        next = curr->next;
        curr->next = prev;
        curr = next;        
        prev = curr;
    }
    head->next = prev;
}

void LinkedList::task5_2()
{
    LinkedList list;
    for (int i = 1; i <= 99; i++)
        list.Insert(i);

    cout << "\n=== Task 5.2: Find, Delete, Reverse ===" << endl;
    list.Print();

    cout << "\nFind(42): " << (list.Find(42) ? "true" : "false") << endl;
    cout << "Find(66): " << (list.Find(66) ? "true" : "false") << endl;
    cout << "Find(100): " << (list.Find(100) ? "true" : "false") << endl;

    cout << "\nDelete(77): " << (list.Delete(77) ? "true" : "false") << endl;
    cout << "Delete(21): " << (list.Delete(21) ? "true" : "false") << endl;
    cout << "Delete(-1): " << (list.Delete(-1) ? "true" : "false") << endl;

    cout << "\nList after deletions:" << endl;
    list.Print();

    cout << "\nReversing list..." << endl;
    list.Reverse();
    list.Print();

    for (int i = 1; i <= 99; i++)
        list.Delete(i);

    cout << "\nIsEmpty(): " << (list.IsEmpty() ? "Yes" : "No") << endl;
}