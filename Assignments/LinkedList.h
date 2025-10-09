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

    void testInit();
};