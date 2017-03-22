#include<iostream>
#include<string>
#pragma once

using namespace std;

class Queue
{
public:
	Queue(int x);
	~Queue();
	void push(char c);
	char pop();
	void printQueue();
	bool isEmpty();
	bool isFull();



private:
	int ArraySize;
	char *Q;
	int Front;
	int Rear;
	int NumItems;
};

