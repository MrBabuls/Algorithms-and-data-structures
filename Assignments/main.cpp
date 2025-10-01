#include "LinearAndBinarySearch.h"
#include "FibonacciAndAckermann.h"
#include <iostream>

using namespace std;

int main() 
{
    int choice;

    cout << "Select a programming task to run:\n";
    cout << "1 - Programming tasks 2\n";
    cout << "2 - Programming tasks 3\n";
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
    case 0:
        cout << "Exiting program.\n";
        break;
    default:
        cout << "Invalid choice.\n";
        break;
    }

    return 0;
}
