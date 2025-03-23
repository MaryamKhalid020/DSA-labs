#ifndef PQUE_H
#define PQUE_H

#include <iostream>
#include "queue.h"

using namespace std;

template <class ItemType>
class PQue {
public:
    PQue(int numPriorities);  // Constructor with dynamic priority levels
    ~PQue();                  // Destructor to free memory

    int IsFull() const;
    int IsEmpty() const;
    void Insert(ItemType newItem, int p);
    void Remove(ItemType& item);

private:
    int n;                  // Number of priority levels
    Que<ItemType>* PQ;      // Pointer to dynamically allocated array of priority queues
};

// Constructor
template<class ItemType>
PQue<ItemType>::PQue(int numPriorities) {
    n = numPriorities;
    PQ = new Que<ItemType>[n];  // Dynamically allocate priority queues
}

// Destructor
template<class ItemType>
PQue<ItemType>::~PQue() {
    delete[] PQ;  // Free allocated memory
}

template<class ItemType>
int PQue<ItemType>::IsFull() const {
    for (int i = 0; i < n; i++) {
        if (!PQ[i].IsFull()) return 0;
    }
    return 1;
}

template<class ItemType>
int PQue<ItemType>::IsEmpty() const {
    for (int i = 0; i < n; i++) {
        if (!PQ[i].IsEmpty()) return 0;
    }
    return 1;
}

template<class ItemType>
void PQue<ItemType>::Insert(ItemType newItem, int p) {
    if (p < 0 || p >= n) {
        cerr << "Invalid priority level!" << endl;
        return;
    }
    PQ[p].Insert(newItem);
}

template<class ItemType>
void PQue<ItemType>::Remove(ItemType& item) {
    for (int i = n - 1; i >= 0; i--) {  // Start from highest priority
        if (!PQ[i].IsEmpty()) {
            PQ[i].Remove(item);
            return;
        }
    }
    cerr << "Priority Queue is empty!" << endl;
}

#endif // PQUE_H
