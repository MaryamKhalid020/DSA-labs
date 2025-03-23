#include <iostream>
#include "6.3.h"  

using namespace std;

int main() {
    LinkedStr list;
    int len, valueToRemove;

    cout << "Enter the number of elements: ";
    cin >> len;
    list.makeStr(len);
    list.displayStr();

    cout << "Removing the first element...\n";
    list.removeFirst();
    list.displayStr();

    cout << "Removing the last element...\n";
    list.removeLast();
    list.displayStr();

    cout << "Enter a value to remove: ";
    cin >> valueToRemove;
    list.remove(valueToRemove);
    list.displayStr();

    return 0;
}
