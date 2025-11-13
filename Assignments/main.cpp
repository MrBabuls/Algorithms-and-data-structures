#include "LinearAndBinarySearch.h"
#include "FibonacciAndAckermann.h"
#include "SimpleSort.h"
#include "LinkedList.h"
#include "Stack.h"
#include "HTMLChecker.h"
#include "BST.h"
#include "Heap.h"

#include <iostream>
#include <string>
using namespace std;

void runTask1() 
{
    cout << "\n--- Task 1: Linear and Binary Search ---\n" << endl;
    LinearAndBinarySearch();
}

void runTask2() 
{
    cout << "\n--- Task 2: Fibonacci and Ackermann ---\n" << endl;
    RunFibonacci();
    RunAckermann();
}

void runTask3() 
{
    cout << "\n--- Task 3: Simple Sort ---\n" << endl;
    RunSimpleSort();
}

void runTask4() 
{
    cout << "\n--- Task 4: Linked List ---\n" << endl;
    LinkedList list;
    list.task5_1();
    list.task5_2();
}

void runTask5() 
{
    cout << "\n--- Task 5: Stack ---\n" << endl;
    Stack stack;
    stack.FillStack();
    stack.Pop();
    stack.Print();
}

void runTask6() 
{
    cout << "\n--- Task 6: HTML Checker ---\n" << endl;
    HTMLChecker checker;
    string filename;
    cout << "Enter HTML file name (e.g. index.html): ";
    cin >> filename;

    bool ok = checker.checkFile(filename);
    if (ok) cout << "HTML is valid!\n";
    else cout << "HTML has errors!\n";
}

void runTask7() 
{
    cout << "\n--- Task 7: BST Test ---\n" << endl;
    BST tree = BST::createSampleTree();
    tree.print();

    cout << "\nNodes: " << tree.countNodes()
        << ", Leaves: " << tree.countLeaves() << endl;

    cout << "\nRemoving 10...\n";
    if (tree.remove(10)) cout << "10 removed successfully.\n";
    else cout << "10 not found.\n";

    tree.print();
    cout << "\nNodes: " << tree.countNodes()
        << ", Leaves: " << tree.countLeaves() << endl;
}

void runTask8() 
{
    cout << "\n--- Task 8: Heap Test ---\n" << endl;
    Heap heap;
    int data[] = { 17, 11, 6, 14, 22, 8, 1, 16, 10, 19, 12, 3, 5, 15, 13 };

    for (int x : data) 
    {
        heap.insert(x);
    }

    cout << "Heap after insertions:" << endl;
    heap.print();

    int sorted[15];
    for (int i = 0; i < 15; i++) 
    {
        sorted[i] = heap.delMin();
    }

    cout << "Sorted array:" << endl;
    cout << "[";

    for (int i = 0; i < 15; i++) 
    {
        cout << sorted[i];
        if (i != 14) cout << ",";
    }
    cout << "]" << endl;
}

void runTask9() 
{
    cout << "\n--- Task 9: Heap Sort Speed Test ---\n" << endl;
    Heap heap;
    heap.runHeapSortSpeedTest();
}

int main() 
{
    int choice;

    while (true) 
    {
        cout << "\nSelect a programming task to run:\n";
        cout << "1 - Programming tasks 1\n";
        cout << "2 - Programming tasks 2\n";
        cout << "3 - Programming tasks 3\n";
        cout << "4 - Programming tasks 4\n";
        cout << "5 - Programming tasks 5\n";
        cout << "6 - Programming tasks 6\n";
        cout << "7 - Programming tasks 7\n";
        cout << "8 - Programming tasks 8\n";
        cout << "9 - Programming tasks 9 (Heap sort speed)\n";
        cout << "0 - Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
        case 1: runTask1(); break;
        case 2: runTask2(); break;
        case 3: runTask3(); break;
        case 4: runTask4(); break;
        case 5: runTask5(); break;
        case 6: runTask6(); break;
        case 7: runTask7(); break;
        case 8: runTask8(); break;
        case 9: runTask9(); break;
        case 0:
            cout << "Exiting program.\n";
            return 0;
        default:
            cout << "Invalid choice.\n";
            break;
        }
    }

    return 0;
}