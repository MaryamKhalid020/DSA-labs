#pragma once
//dynamic stack.h
template<class ItemType>

class Stack {
public:
	Stack();
	Stack(int max);
	~Stack();
	int Isempty() const;
	int Isfull() const;
	void Push(ItemType newItem);
	void Pop(ItemType& item);

private:
	int top;
	int maxStack;
	ItemType* items;
};