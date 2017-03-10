
#include <iostream>
#include <string>
using namespace std;



/**
* @FunctionName: Queue
* @Description: 
*     Implementation of a char queue
*/
class Queue
{
  private: ////////////////////////////////////////////
  
  int ArraySize;
  char *Q;
  int Front;
  int Rear;
  int NumItems;
  
  public: ////////////////////////////////////////////
  
  /**
  * @FunctionName: Queue
  * @Description: 
  *     Class constructor
  * @Params:
  *    int insize - initial queue size
  * @Returns:
  *    void
  */
  Queue(int insize);
 
  /**
  * @FunctionName: push
  * @Description: 
  *     Adds a character to the queue
  * @Params:
  *    char c - character to add 
  * @Returns:
  *    void
  */
  void Push(char c);
  
  /**
  * @FunctionName: pop
  * @Description: 
  *     Returns a character from the top of the queue
  * @Params:
  *    None 
  * @Returns:
  *    void
  */
  char Pop();
 
  /**
  * @FunctionName: printQueue
  * @Description: 
  *     Prints queue to stdout for debugging purposes
  * @Params:
  *    None
  * @Returns:
  *    void
  */
  void PrintQueue();
 
  /**
  * @FunctionName: empty
  * @Description: 
  *     Checks to see if queue is empty.
  * @Params:
  *    None 
  * @Returns:
  *    bool - true if empty / false otherwise
  */
  bool Empty();
  
  /**
  * @FunctionName: full
  * @Description: 
  *     Checks if queue is full
  * @Params:
  *    None 
  * @Returns:
  *    bool - true if full / false otherwise
  */
  bool Full();
 
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
* @FunctionName: Stack
* @Description: 
*     Implementation of a char stack
*/
class Stack
{
  private: ////////////////////////////////////////////
  
  char *S;
  int top;
  int size;
  
  public: ////////////////////////////////////////////
  
  /**
  * @FunctionName: Stack
  * @Description: 
  *     Class constructor
  * @Params:
  *    int insize - initial stack size
  * @Returns:
  *    void
  */
  Stack(int insize);
 
  
  /**
  * @FunctionName: push
  * @Description: 
  *     Adds a character to the stack
  * @Params:
  *    char c - character to add 
  * @Returns:
  *    void
  */
  void Push(char c);
 
  
  /**
  * @FunctionName: pop
  * @Description: 
  *     Returns a character from the top of the stack
  * @Params:
  *    None 
  * @Returns:
  *    void
  */
  char Pop();
  
  
  /**
  * @FunctionName: printStack
  * @Description: 
  *     Prints stack to stdout for debugging purposes
  * @Params:
  *    None
  * @Returns:
  *    void
  */
  void PrintStack();
 
  
  /**
  * @FunctionName: empty
  * @Description: 
  *     Checks to see if stack is empty.
  * @Params:
  *    None 
  * @Returns:
  *    bool - true if empty / false otherwise
  */
  bool Empty();
 
  
  /**
  * @FunctionName: full
  * @Description: 
  *     Checks if stack is full
  * @Params:
  *    None 
  * @Returns:
  *    bool - true if full / false otherwise
  */
  bool Full();
 
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Convert{
private: ////////////////////////////////////////////
   int Size
   Stack *S;
   Queue *Q;
public: ////////////////////////////////////////////
  Convert();
  
  
  void TempFunc();
  
};
