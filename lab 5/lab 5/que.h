#pragma once
#ifndef QUEUE_H
#define QUEUE_H
template<class T>
class Queue {
	int count, front, rear, MAX;
	T* queue;
public:
	Queue();
	Queue(int max);
	~Queue();
	bool isFull() const;
	bool isEmpty() const;
	void insert(T item);
	void remove(T& item);
};
template<class T>
Queue<T>::Queue() {
	count = 0, front = -1, rear = -1, MAX = 500;
	queue = new T[MAX];
}
template<class T>
Queue<T>::Queue(int max) {
	MAX = max;
	count = 0, front = -1, rear = -1;
	queue = new T[MAX];
}
template<class T>
Queue<T>::~Queue() {
	delete[] queue;
}
template<class T>
bool Queue<T>::isFull() const {
	return (count == MAX);
}
template<class T>
bool Queue<T>::isEmpty() const {
	return (count == 0);
}
template<class T>
void Queue<T>::insert(T item) {
	if (isFull()) {
		cerr << "Queue overflow."; exit(1);
	}
	rear = (rear + 1) % MAX;
	queue[rear] = item;
	count++;
}
template<class T>
void Queue<T>::remove(T& item) {
	if (isEmpty()) {
		cerr << "Queue underflow."; exit(1);
	}
	item = queue[front];
	front = (front + 1) % MAX;
	count++;
}
#endif