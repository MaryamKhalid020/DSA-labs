//dynamic driver.cpp
#include<iostream>
#include "dstack.h"

using namespace std;

int main()
{
	Stack<int> IntStack;
	Stack<float> FloatStack;
	int data;
	float val;

	IntStack.Push(35);
	FloatStack.Push(3.14159); 

    IntStack.Pop(data);
	cout << data << endl;

	FloatStack.Pop(val);
	cout <<val<< endl;
	return 0;
}