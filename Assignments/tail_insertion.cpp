/**
* Homework-1
* Marcus Moisant 
* @Description: 
*     This program contains functions with methods on how to insert data into a list
*     either by inserting at the front, FrontSert, or at the end of the linked list, EndSert.
* 1063 Data Structures
* Spring 2017
* 10 02 2017
*/
#include <iostream>

struct Node
{
  int Data;
  Node *Next;
};

using namespace std;

class List
{
  private:
  Node *Head;
  Node *Tail;
  public:
  List()
  {
    Head = NULL;
  }
    
      /**
* @FunctionName: FrontSert
* @Description: 
*     creates head pointer so new nodes with data can be inserted
*     at front of linked list. If list is empty creates new node
*     and declares new node to be head.
* @Params:
*    int x
* @Returns:
*    void
*/
  void FrontSert(int x)
  {
    Node *Temp = new Node; //create Node
    Temp->Data = x;
    Temp->Next = NULL;
      
    if(!Head)
    {
      Temp->Next = Head;
    }
    Head = Temp;  
  }
  
  
  /**
* @FunctionName: EndSert
* @Description: 
*     creates tail pointer so new nodes with data can be inserted
*     at end of linked list.
* @Params:
*    int x
* @Returns:
*    void
*/
 void EndSert(int x)
{
    // Creates a temp to hold the last node & set tail's data and next
    Node *Tail = new Node;

    Tail->Data = x;
    Tail->Next = NULL;

    // If the linked list is empty then set head = tail
    if (Head == NULL) 
    {
        Head = Tail;
    } 
    else 
    {
        // Creates a temp node and sets it to head
        Node *temp = new Node;

        temp = Head;

        // Uses temp to find the tail node
        while (temp->Next != NULL) {
            temp = temp->Next;
        }

        // Appends the last node with last
        temp->Next = Tail;
    }
} 

  /**
* @FunctionName: PrintList
* @Description: 
*     Prints list formed from other functions, frontsert or endsert. 
*     
* @Params:
*   
* @Returns:
*    void
*/
 void PrintList()
 {
   if(!Head)
   {
     cout<<"Empty"<<endl;
     return;
   }
   else
   {
     Node *Temp = Head;
     while(Temp != NULL)
     {
      cout<<Temp->Data<<"->";
      Temp = Temp->Next;
     } 
   }
 }
};
int main()
{
  srand(7777777 );
  List L;
  for(int i=0;i<10;i++)
  {
    L.EndSert(rand()%100);
  }
  L.PrintList();
 
  
  return 0;
}
