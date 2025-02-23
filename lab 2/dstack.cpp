//dynamic stack.cpp
#include<stdlib.h>
#include<iostream>
#include "dstack.h"
using namespace std;

template<class ItemType>
Stack<ItemType>::Stack()
{
	maxStack = 500;
	top = -1;
	items = -new ItemType[500];
}

template<class ItemType>
Stack<ItemType>::Stack(int max)
{
	maxStack = max;
	top = -1;
	items = new ItemType[max];
}

template<class ItemType>
Stack<ItemType>::~Stack()
{
	delete[] items;
}

template<class ItemType>
int Stack<ItemType>::Isempty()const
{
	return (top == -1);
}

template<class ItemType>
int Stack <ItemType> ::Isfull() const
{
	return (top == maxStack - 1);
}

template<class ItemType>
void Stack<ItemType>::Push(ItemType newItem)
{
	if (Isfull())
	{
		cout << "stack overflow" << endl;
		exit(1);
	}
	top++;
	items[top] = newItem;
}

template<class ItemType>
void Stack<ItemType> ::Pop(ItemType& item)
{
	if (Isempty())
	{
		cout << "stack underflow" << endl;
		exit(1);
	}
	item = items[top];
	top--;
}