//stack.cpp
#include<stdlib.h>
#include<iostream>
#include "stack.h"
using namespace std;
Stack::Stack()
{
	top = -1;
}

int Stack::Isempty() const
{
	return (top == -1);
}

int Stack::Isfull() const
{
	return (top == MAX_ITEMS - 1);
}

void Stack::Push(ItemType newItem)
{
	if (Isfull())
	{
		cout << "stack overflow" << endl;
		exit(1);
	}
	top++;
	items[top] = newItem;
}

void Stack::Pop(ItemType& item)
{
	if (Isempty())
	{
		cout << "stack underflow" << endl;
		exit(1);
	}
	item = items[top];
	top--;
}
//exercise 2.1 a
ItemType Stack::Peek() const {
    if (Isempty()) {
        cout << "Stack is empty" << endl;
        exit(1); 
    }
    return items[top];
}
