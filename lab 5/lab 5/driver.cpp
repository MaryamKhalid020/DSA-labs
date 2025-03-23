#include<iostream>
#include"que.h"
#include"fileName.h"
using namespace std;

int main()
{
	PQue<int> pq;
	int item;
	pq.insert(10, 1);
	pq.insert(20, 2);
	pq.insert(30, 3);
	pq.insert(40, 4);
	pq.insert(50, 5);
	pq.insert(60, 6);
	pq.insert(70, 7);
	pq.insert(80, 8);
	pq.insert(90, 9);
	pq.insert(100, 0);
}
