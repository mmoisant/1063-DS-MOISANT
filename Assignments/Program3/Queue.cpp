#include "Queue.h"


Queue::Queue(int x)
{
	ArraySize = x;
	Q = new char[ArraySize];
	Front = 0;
	Rear = 0;
	NumItems = 0;
}

void Queue::push(char c)
{
	if (!isFull())
	{
		Q[Rear] = c;
		Rear = (Rear+1) % ArraySize;
		NumItems++;
	}
	else
	{
		cout << "Queue Full!\n";
	}
}

char Queue::pop()
{
	if (!isEmpty())
	{
		int temp = Q[Front];
		Front = (Front + 1) % ArraySize;
		NumItems--;
		return temp;
	}
	else
	{
		cout << "Queue is empty!\n";
	}
}

void Queue::printQueue()
{
	for (int i = Front, j = 0; j < NumItems; j++, i = (i + 1) % ArraySize)
	{
		cout << Q[i] << " ";
	}
	cout << "\n";
}

bool Queue::isEmpty()
{
	return (NumItems == 0);
}

bool Queue::isFull()
{
	return (NumItems == ArraySize);
}


Queue::~Queue()
{
}
