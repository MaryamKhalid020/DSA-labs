#ifndef PQUE_H
#define PQUE_H

#include <iostream>
#include "queue.h"

using namespace std;

template <class ItemType>
class PQue {
public:
    PQue(int n);  // Constructor to accept dynamic priority levels
    ~PQue();      // Destructor
    int IsFull() const;
    int IsEmpty() const;
    void Insert(ItemType newItem, int p);
    void Remove(ItemType& item);

private:
    int numPriorities;   // Number of priority levels
    Que<ItemType>* PQ;   // Dynamically allocated array of priority queues
};

// ** Implementation **

template<class ItemType>
PQue<ItemType>::PQue(int n) : numPriorities(n) {
    PQ = new Que<ItemType>[numPriorities]; // Dynamically allocate array
}

template<class ItemType>
PQue<ItemType>::~PQue() {
    delete[] PQ; // Free allocated memory
}

template<class ItemType>
int PQue<ItemType>::IsFull() const {
    for (int i = 0; i < numPriorities; i++) {
        if (!PQ[i].IsFull()) return 0;
    }
    return 1;
}

template<class ItemType>
int PQue<ItemType>::IsEmpty() const {
    for (int i = 0; i < numPriorities; i++) {
        if (!PQ[i].IsEmpty()) return 0;
    }
    return 1;
}

template<class ItemType>
void PQue<ItemType>::Insert(ItemType newItem, int p) {
    if (p < 0 || p >= numPriorities) {
        cerr << "Invalid priority level!" << endl;
        return;
    }
    PQ[p].Insert(newItem);
}

template<class ItemType>
void PQue<ItemType>::Remove(ItemType& item) {
    for (int i = numPriorities - 1; i >= 0; i--) {
        if (!PQ[i].IsEmpty()) {
            PQ[i].Remove(item);
            return;
        }
    }
    cerr << "Priority Queue is empty!" << endl;
}

#endif // PQUE_H


#include <iostream>
#include "pque.h"

using namespace std;

int main() {
    int numPriorities;
    cout << "Enter the number of priority levels: ";
    cin >> numPriorities;

    PQue<int> pq(numPriorities);  // Instantiate with dynamic priority levels

    // Inserting elements with different priority levels
    pq.Insert(10, 2);
    pq.Insert(20, 5);
    pq.Insert(30, 5);
    pq.Insert(40, 1);

    // Removing elements and displaying them
    int item;
    pq.Remove(item);
    cout << "Removed: " << item << endl;

    pq.Remove(item);
    cout << "Removed: " << item << endl;

    return 0;
}
