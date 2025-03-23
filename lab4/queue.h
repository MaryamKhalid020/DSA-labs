#pragma once
typedef int ItemType;

class Queue {
private:
    static const int maxQue = 100; 
    ItemType items[maxQue] = {};  
    int front, rear, count;

public:
    Queue();
    int IsEmpty();
    int IsFull();
    void Insert(ItemType newItem);
    void Remove(ItemType& item);
};
