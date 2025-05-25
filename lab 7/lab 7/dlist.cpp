#include <iostream>
#include "doubly.h"

using namespace std;

void displayMenu() {
    cout << "\n--- Long Integer Linked List Menu ---\n";
    cout << "1. Push Front\n";
    cout << "2. Push Back\n";
    cout << "3. Pop Front\n";
    cout << "4. Pop Back\n";
    cout << "5. Display First Element\n";
    cout << "6. Display Last Element\n";
    cout << "7. Check if List is Empty\n";
    cout << "8. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    doubleLinked<long long> longIntList;
    int choice;
    long long value;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter long integer to insert at front: ";
            cin >> value;
            longIntList.pushFront(value);
            cout << value << " inserted at the front.\n";
            break;
        case 2:
            cout << "Enter long integer to insert at back: ";
            cin >> value;
            longIntList.pushBack(value);
            cout << value << " inserted at the back.\n";
            break;
        case 3:
            if (!longIntList.isEmpty()) {
                cout << "Removed from front: " << longIntList.popFront() << "\n";
            }
            else {
                cout << "List is empty!\n";
            }
            break;
        case 4:
            if (!longIntList.isEmpty()) {
                cout << "Removed from back: " << longIntList.popBack() << "\n";
            }
            else {
                cout << "List is empty!\n";
            }
            break;
        case 5:
            if (!longIntList.isEmpty()) {
                cout << "First element: " << longIntList.startOfList() << "\n";
            }
            else {
                cout << "List is empty!\n";
            }
            break;
        case 6:
            if (!longIntList.isEmpty()) {
                cout << "Last element: " << longIntList.endOfList() << "\n";
            }
            else {
                cout << "List is empty!\n";
            }
            break;
        case 7:
            cout << (longIntList.isEmpty() ? "List is empty.\n" : "List is not empty.\n");
            break;
        case 8:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice! Please enter a number between 1-8.\n";
            break;
        }
    } while (choice != 8);

    return 0;
}