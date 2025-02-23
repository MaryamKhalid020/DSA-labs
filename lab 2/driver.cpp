//driver.cpp
#include<iostream>
#include "stack.h"

using namespace std;

int main()
{
	Stack s;
	int item;
	for (int i = 0; i < 20; i++)
		s.Push(i);

	for (int i = 0; i < 20; i++)
	{
		s.Pop(item);
		cout << item << endl;
	}
	return 0;
}