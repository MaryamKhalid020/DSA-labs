#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

using namespace std;

template <class ItemType>
class Que {
private:
    struct Node {
        ItemType data;
        Node* next;
    };
    Node* front;
    Node* rear;

public:
    Que();
    ~Que();
    bool IsFull() const;
    bool IsEmpty() const;
    void Insert(ItemType item);
    void Remove(ItemType& item);
};

// Constructor
template <class ItemType>
Que<ItemType>::Que() {
    front = rear = nullptr;
}

// Destructor
template <class ItemType>
Que<ItemType>::~Que() {
    ItemType temp;
    while (!IsEmpty()) {
        Remove(temp);
    }
}

// Check if queue is full (always returns false for linked list implementation)
template <class ItemType>
bool Que<ItemType>::IsFull() const {
    return false;
}

// Check if queue is empty
template <class ItemType>
bool Que<ItemType>::IsEmpty() const {
    return front == nullptr;
}

// Insert element into queue
template <class ItemType>
void Que<ItemType>::Insert(ItemType item) {
    Node* newNode = new Node{ item, nullptr };
    if (rear) rear->next = newNode;
    rear = newNode;
    if (!front) front = newNode;
}

// Remove element from queue
template <class ItemType>
void Que<ItemType>::Remove(ItemType& item) {
    if (IsEmpty()) {
        cerr << "Queue is empty!" << endl;
        return;
    }
    Node* temp = front;
    item = front->data;
    front = front->next;
    if (!front) rear = nullptr;
    delete temp;
}

#endif // QUEUE_H
