#include <iostream>
#include "queue.h"
using namespace std;

Queue::Queue() {
    front = 0;
    rear = 0;
    count = 0;
    for (int i = 0; i < maxQue; i++) {
        items[i] = 0;  
    }
}


int Queue::IsEmpty()
{
    return (count == 0);
}

int Queue::IsFull()
{
    return (count == maxQue);
}

void Queue::Insert(ItemType newItem)
{
    if (IsFull())
        cout << "Over Flow";
    else
    {
        items[rear] = newItem;
        rear = (rear + 1) % maxQue;
        ++count;
    }
}

void Queue::Remove(ItemType& item)
{
    if (IsEmpty())
        cout << "Under Flow";
    else
    {
        item = items[front];
        front = (front + 1) % maxQue;
        --count;
    }
}
