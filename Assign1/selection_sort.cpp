//***************************************************************************
//
//  selection_sort.cpp
//  CSCI 241 Assignment: 1 
//
//  Created by: Jacob Kurbis (z1945650)
//
//**************************************************************************/*

#include <iostream> 
#include <iomanip>
#include <cstdlib>

#define maxValDsply 8 //Symbolic Constant that holds max value output for each line

using namespace std;

//Fucntion Protoypes
void print();

int main()
{

//Variables
  int min_index,//Integer that holds the current array index
      array[1000],//Array that can hold up to 1000 integer elements
      arraySize = 0;//Integer that holds the number of elements in the array
 
//Loop that reads random#.txt file
  while(cin >> array[arraySize])
  {
    arraySize++;
//Selection Sort Algorithm
    for(int i = 0; i < arraySize - 1 ; i++)
    {
      min_index  = i;
    
      for( int j = i + 1; j < arraySize; j++)
      {
        if( array[j] <  array[min_index] )
        {
          min_index = j;
        }
      }
//Swapping the order of intgers in array
      int temp = array[min_index];
      array[min_index] = array[i];
      array[i] = temp;
    }
  }

 //Loop to print out each value of Array
 for(int i = 0; i < arraySize; i++)
   {
//Nested Loop to determine if 8 values have been displayed
   for( int j = i; j < i + maxValDsply && j < arraySize; j++)
     {
     cout << setw(8) << setprecision(0) << fixed << array[j] << " ";
     }
     
     i += 7;
     cout << endl;
   }

  print();

return 0;
}

print()
{
  cout << "Jacob Kurbis" << endl;
}
