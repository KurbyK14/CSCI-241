//***************************************************************************
//
//  bubble_sort.cpp
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


int main()
{

//Variables
int array[1000],//Array that can hold up to 1000 integer elements
    arraySize = 0;//Integer that holds the number of elements in the array
 
//Loop that reads random#.txt file
while(cin >> array[arraySize])
  {
  arraySize++;
//Bubble Sort Algorithm
  for(int i = 0; i < arraySize; i++)
    {
    int swaps = 0; //flag to detect if swap has changed
    
    for( int j = 0; j < arraySize - i - 1; j++)
      {
      if( array[j] >  array[j + 1] )//when the current element is bigger than the next element
        {
        //Swapping the order of integers in Array
        int temp = array[j];
            array[j] = array[j+1];
            array[j+1] = temp;
        
        swaps = 1; //setting swap flag
        }
      }
    
    if( !swaps )
      {
      break; //If no swap, then array is sorted and stops bubble sort
      }
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

return 0;
}
