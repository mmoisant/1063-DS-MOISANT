 /**
* Homework-4
* Marcus Moisant
* @Description: 
*     This program searches BTS by establishing a middle var and 
*     comparing values to see if and where an index exists. 
* 1063 Data Structures
* Spring 2017
* 08 03 2017
*/


/**
* @FunctionName: BinarySearch
* @Description: 
*     Implementation of a binary search on an array of values
* @Params:
*     int* data - data array
*     int  key  - key to search for
* @Returns: 
*    int - positive value = index / negative value = not found
*/
int BinarySearch(int* data,int key,int size)
{
  int left = 0;
  int right = size-1;
  int middle = (left + right) / 2;
  
  bool found = false;
  
  
  while(!found)
  {
    if(data[middle] == key)
    {
      return middle;
    }
    else if(middle == left || middle == right)
    {
      found == false;
      break;
    }
    else
    {
      if(key < data[middle])
      {
        right = middle;
      }else
      {
        left = middle;
      }
      middle = (left + right) / 2;
    }
    
  }
  
  return -1;
}
