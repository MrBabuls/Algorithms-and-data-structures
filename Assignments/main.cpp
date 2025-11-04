#include "LinearAndBinarySearch.h"
#include "FibonacciAndAckermann.h"
#include "SimpleSort.h"
#include "LinkedList.h"
#include "Stack.h"
#include "HTMLChecker.h"
#include "BST.h"

#include <iostream>
using namespace std;

int main()
{
    int choice;
    LinkedList list;
    Stack stack;
    HTMLChecker checker;
    string filename;

    while (true)
    {
        cout << "Select a programming task to run:\n";
        cout << "1 - Programming tasks 1\n";
        cout << "2 - Programming tasks 2\n";
        cout << "3 - Programming tasks 3\n";
        cout << "4 - Programming tasks 4\n";
        cout << "5 - Programming tasks 5\n";
        cout << "6 - Programming tasks 6\n";
        cout << "7 - Programming tasks 7\n";
        cout << "0 - Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "\n" << endl;
            LinearAndBinarySearch();
            break;

        case 2:
            cout << "\n" << endl;
            RunFibonacci();
            RunAckermann();
            break;

        case 3:
            cout << "\n" << endl;
            RunSimpleSort();
            break;

        case 4:
            cout << "\n" << endl;
            list.task5_1();
            list.task5_2();
            break;

        case 5:
            cout << "\n" << endl;
            stack.FillStack();
            stack.Pop();
            stack.Print();
            break;

        case 6:
            cout << "\n" << endl;
            cout << "Enter HTML file name (e.g. index.html): ";
            cin >> filename;
            {
                bool ok = checker.checkFile(filename);
                if (ok) cout << "HTML is valid!\n";
                else cout << "HTML has errors!\n";
            }
            break;

        case 7:
        {
            cout << "\n" << endl;
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

            break;
        }

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
