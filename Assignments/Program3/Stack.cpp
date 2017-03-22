#include "Stack.h"


Stack::Stack(int x)
{
	size = x;
	top = -1;
	S = new char[size];
}

void Stack::push(char c)
{
	if (!isFull())
	{
		S[++top] = c;
		
	}
	else
	{
		cout << "Stack Overflow!\n";
	}
}

char Stack::pop()
{
	if (!isEmpty())
	{
		return S[top--];
	}
	else
	{
		return -1;
	}
	
}

void Stack::printStack()
{
	for (int i = top; i >= 0; i--)
	{
		cout << S[i] << " ";
	}
	cout << endl;
}

bool Stack::isEmpty()
{
	bool empty = true;

	if (top != (-1))
	{
		empty = false;
	}

	return empty;
}

bool Stack::isFull()
{
	bool full = true;

	if (top != (size - 1))
	{
		full = false;
	}

	return full;
}

char Stack::peek()
{
		if (S[top] == '(')
		{
			return 0;
		}
		else if (S[top] == '+' || S[top] == '-')
		{
			return 1;
		}
		else if (S[top] == '*' || S[top] == '/' || S[top] == '%')
		{
			return 2;
		}
		else if (S[top] == '^')
		{
			return 3;
		}
		else
			return 4;
}



Stack::~Stack()
{
}
