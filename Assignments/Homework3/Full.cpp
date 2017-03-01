/**
* Homework-3
* Marcus Moisant
* @Description: 
*     This program printes a queue to screen.
* 1063 Data Structures
* Spring 2017
* 01 03 2017
*/

#include <iostream>
#include <random>

using namespace std;

class ArrQueue{
private:
  int ArraySize;
  int *Q;
  int Front;
  int Rear;
  int NumItems;
public:
  ArrQueue(int size=10)
  {
    ArraySize = size;
    Q = new int[ArraySize];
    Front = Rear = NumItems = 0;
  }
  
  bool Push(int value)
  {
    if(Full())
    {
      cout<<"Queue Full!"<<endl;
      return false;
    }
    Q[Rear] = value;
    Rear = (Rear + 1) % ArraySize;
    NumItems++;
    return true;
  }
  
  int Pop()
  {
    if(Empty())
    {
      cout<<"Queue Empty!"<<endl;
      return false;
    }
    int Temp = Q[Front];
    Front = (Front + 1) % ArraySize;
    NumItems--;
    return Temp;
  }
  
  bool Empty()
  {
    return (NumItems == 0);
  }
  
  bool Full()
  {
    return (NumItems == ArraySize);
  }
  
  void PrintFR()
  {
    cout<<"Front: "<<Front<<"Rear: "<<Rear<<endl;
  }
  
  
  /**
* @FunctionName: Print
* @Description: (of fix)
*     FIX: FRONT AND REAR WERE BOTH EQUAL 
*     TO 0 & THE WOULD NOT PRINT. FIX BY 
*     USING isFull FUNCTION TO SEE IF QUEUE 
*     WAS FULL & KEEP PRINTING 
* @Params:
*    NONE
* @Returns:
*    NONE
*/
  //////FIX ME/////
  void Print()
  {
  int Index = Front;
  bool isFull = Full();

  while(Index != Rear || isFull)
  {
    cout<<Q[Index]<<" ";
    Index = ((Index + 1) % (ArraySize));
    isFull = false;
  }
  cout<<endl;  
}

/** void Print()
  {
    //FIX ME!ALTERATIVE FIX
    int Index=Front;
    for(int i=0;i<NumItems;i++)
    {
      cout<<Q[Index]<<" ";
      Index = ((Index + 1) % (ArraySize));
    }
    cout<<endl;
  }*/
  
};

int main() 
{
    srand(983475);
    ArrQueue Q;
    int r = 0;
    bool result;
    
    for(int i=0;i<12;i++)
    {
      r = rand()%100;
      result = Q.Push(r);
      if(result)
        cout<<r<<endl;
    }
    Q.PrintFR();
    Q.Print();
    cout<<Q.Pop()<<endl;
    cout<<Q.Pop()<<endl;
    cout<<Q.Pop()<<endl;
    cout<<Q.Pop()<<endl;
    cout<<Q.Pop()<<endl;

    Q.Print();
    cout<<Q.Pop()<<endl;
    cout<<Q.Pop()<<endl;
    cout<<Q.Pop()<<endl;
    for(int i=0;i<3;i++)
    {
      r = rand()%100;
      result = Q.Push(r);
      if(result)
        cout<<r<<endl;
    }
    Q.Print();
    for (int m = 0; m<6; m++)
    cout<<Q.Pop()<<endl;
    Q.Print();
    return 0;
}
