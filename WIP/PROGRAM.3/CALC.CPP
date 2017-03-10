
#include <iostream>
#include <string>
#include "Calculator.h"
using namespace std;


Queue::Queue(int insize)
{
    ArraySize = insize;
    Q = new char[ArraySize];
    Front = Rear = NumItems = 0;
}
  
void Queue::Push(char c)
{
    if(Full()){
      cout<<"Queue Full!"<<endl;
      return;
    }
    Q[Rear] = c;
    Rear = (Rear + 1) % ArraySize;
    NumItems++;
    return;
  }
  
char Queue::Pop()
{
    if(Empty()){
      cout<<"Queue Empty!"<<endl;
      return false;
    }
    int Temp = Q[Front];
    Front = (Front + 1) % ArraySize;
    NumItems--;
    return Temp;
  }
  
void Queue::PrintQueue()
{
    for(int i=Front,j=0;j<NumItems;j++,i=(i+1)%ArraySize){
      cout<<Q[i]<<" ";
    }
    cout<<endl;
  }
  
bool Queue::Empty()
{
    return (NumItems == 0);
}

bool Queue::Full()
{
    return (NumItems == ArraySize);
}

Stack::Stack(int insize)
{
    size = insize;
    top = -1;
    S = new char[size];
}

void Stack::Push(char c)
{
    if(!Full())
    {
      S[++top] = c;
    }
    else
    {
      cout<<"Stack Overflow!"<<endl;
    }
}

char Stack::Pop()
{
    if(!Empty())
      return S[top--];
    else
      return -1;
}

void Stack::PrintStack()
{
    for(int i=top;i>=0;i--)
    {
      cout<<S[i]<<" ";
    }
    cout<<endl;
  }

bool Stack::Empty()
{
    return top == -1;
  }

bool Stack::Full()
{
    return top == size-1;
}

Convert::Convert()
{

    S = new Stack(20);
    Q = new Queue(20);
  }

void Convert::TempFunc()
{
    char temp;
    int i;
    string infix = "(3+4)*9-(3+4)*8";

    for(int i=0;i<infix.length();i++)
    {
      S->Push(infix[i]);
    }
    
    while(!S->Empty())
    {
      temp = S->Pop();
      cout<<temp;
      //we could simply do cout<<s1.pop(); as well. 
    }
  }
