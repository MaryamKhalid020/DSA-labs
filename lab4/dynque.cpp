#include <iostream>
#include "dynque.h"
using namespace std;

template <class ItemType>
Que<ItemType>::Que()   
{
    maxQue = 501;
    front = 0;
    rear = 0;
    count = 0;
    items = new ItemType[maxQue];  
}

template <class ItemType>
Que<ItemType>::Que(int max) {
    items = new ItemType[max];  
    front = rear = count = 0;
}


template <class ItemType>
Que<ItemType>::~Que() {
    delete[] items;   
}

template <class ItemType>
int Que<ItemType>::IsFull() const {
    return (count == maxQue);
}

template <class ItemType>
int Que<ItemType>::IsEmpty() const {
    return (count == 0);
}

template <class ItemType>
void Que<ItemType>::Insert(ItemType newItem) {
    if (IsFull())
        cout << "Over Flow\n";
    else {
        items[rear] = newItem;
        rear = (rear + 1) % maxQue;
        count++;
    }
}

template <class ItemType>
void Que<ItemType>::Remove(ItemType& item) {
    if (IsEmpty())
        cout << "Under Flow\n";
    else {
        item = items[front];
        front = (front + 1) % maxQue;
        count--;
    }
}
