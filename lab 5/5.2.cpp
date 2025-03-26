
#include <iostream>
#include "pque.h"

using namespace std;

int main() {
    int numPriorities;
    cout << "Enter the number of priority levels: ";
    cin >> numPriorities;

    PQue<int> pq(numPriorities);  
    pq.Insert(10, 2);
    pq.Insert(20, 5);
    pq.Insert(30, 5);
    pq.Insert(40, 1);
    
    int item;
    pq.Remove(item);
    cout << "Removed: " << item << endl;

    pq.Remove(item);
    cout << "Removed: " << item << endl;

    return 0;
}
