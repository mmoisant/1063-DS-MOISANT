 /**
* Homework-3
* Marcus Moisant
* @Description: 
*     This program printes a queue to screen.
* 1063 Data Structures
* Spring 2017
* 01 03 2017
*/
 
 
 /**
* @FunctionName: Print
* @Description: (of fix)
*     FIX: FRONT AND REAR WERE BOTH EQUAL 
*     TO 0 & THE WOULD NOT PRINT. FIX BY USING 
*     isFull FUNCTION TO SEE IF QUEUE WAS FULL 
*     & KEEP PRINTING 
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
