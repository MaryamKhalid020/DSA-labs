#include "que.h"
template <class ItemType>
class PQue {
public:
	PQue();
	int IsEmpty() const;
	int IsFull() const;
	void insert(ItemType newitem, int p);
	void Remove(ItemType& item);

private:
	Que<ItemType> pQ[10];
};

template <class ItemType>
void PQue<ItemType>::insert(ItemType newitem, int p) {
	pQ[p].insert(newitem);
}
template<class ItemType>
PQue<ItemType>::PQue() {
	for (int i = 0; i < 10; i++) {
		pQ[i] = Que<ItemType>();
	}
}

template <class ItemType>
void PQue<ItemType>::Remove(ItemType& item) {
	for (int i = 0; i < 10; i++) {
		if (!pQ[i].isEmpty()) {
			pQ[i].remove(item);
			return true;
		}
	}
	return false;
}

template <class ItemType>
int PQue<ItemType>::IsEmpty() const { // Change return type to bool
	for (int i = 0; i < 10; i++) {
		if (!pQ[i].isEmpty()) {
			return false;
		}
	}
	return true;
}

template <class ItemType>
int PQue<ItemType>::IsFull() const { // Change return type to bool
	for (int i = 0; i < 10; i++) {
		if (!pQ[i].isFull()) {
			return false;
		}
	}
	return true;
}
#pragma once
