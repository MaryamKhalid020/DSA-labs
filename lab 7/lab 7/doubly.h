#pragma once
#include<iostream>
using namespace std;
template<class T>
class doubleLinked {

	struct Node {
		T info;
		Node* next;
		Node* prev;
		Node(const T& x, Node* prev, Node* next) :info(x), prev(prev), next(next) {};
	};
	typedef Node* nodeptr;
	nodeptr head;
	nodeptr tail;
public:
	doubleLinked() {
		head = nullptr;
		tail = nullptr;
	}
	doubleLinked(T itemsArray[]) :head(nullptr), tail(nullptr) {
		for (int i = 0; i < sizeof(itemsArray); i++)
		{
			pushBack(itemsArray[i]);
		}
	}
	~doubleLinked() {
		while (head != nullptr) {
			head = head->next;
			delete head->prev;
		}
	}
	T startOfList() {
		return head->info;
	}
	T endOfList() {
		return tail->info;
	}
	bool isEmpty() {
		return (!head || !tail);
	}
	operator bool() const {
		return !isEmpty();
	}
	void pushBack(const T& item) {
		tail = new Node(item, tail, nullptr);
		if (tail->prev)
		{
			tail->prev->next = tail;//assigning the node back of the tail to point to the tail
		}
		else if (isEmpty()) head = tail; //for empty node inserting the first element 
	}
	void pushFront(const T& item) {
		head = new Node(item, nullptr, head);
		if (head->next) {
			head->next->prev = head;
		}
		else if (isEmpty()) tail = head;
	}
	T popBack() {
		if (isEmpty()) {
			cout << "List is empty" << endl;
			return T();
		}
		else {
			nodeptr temp = tail;
			T x = temp->info;
			tail = tail->prev;
			if (tail) tail->next = nullptr;
			else head = nullptr;
			delete temp;
			return x;
		}
	}
	T popFront() {
		if (isEmpty()) {
			cout << "List is empty" << endl;
			return T();
		}
		else {
			nodeptr temp = head;
			T x = temp->info;
			head = head->next;
			if (head) head->prev = nullptr;
			else tail = head;
		}
	}
};
