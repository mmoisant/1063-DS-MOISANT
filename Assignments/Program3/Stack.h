#include<iostream>
#include<string>
#pragma once

using namespace std;

class Stack
{
public:
	Stack(int x);
	~Stack();
	void push(char c);
	char pop();
	void printStack();
	bool isEmpty();
	bool isFull();
	char peek();

private:
	char *S;
	int top;
	int size;
};

