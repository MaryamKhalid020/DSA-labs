#pragma once
//stack.h
#define MAX_ITEMS 100
typedef int ItemType;

class Stack {
public:
	Stack();
	int Isempty() const;
	int Isfull() const;
	void Push(ItemType newItem);
	void Pop(ItemType& item);
	void Peek() const;

private:
	int top;
	ItemType items[MAX_ITEMS];
};