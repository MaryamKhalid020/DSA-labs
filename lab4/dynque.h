#include <iostream>
#include <string>

template <class ItemType>
class Que {
public:
    Que();
    Que(int max);   
    ~Que();         

    int IsFull() const;
    int IsEmpty() const;
    void Insert(ItemType newItem);
    void Remove(ItemType& item);

private:
    int front;
    int rear;
    //int maxQue;
    int count;
    ItemType* items;   
}; 
