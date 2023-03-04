//***************************************************************************
//
//  merge_sort.cpp
//  CSCI 241 Assignment: 3 
//
//  Created by: Jacob Kurbis (z1945650)
//
//**************************************************************************/

#include <iostream> 
#include <iomanip>
#include <cstdlib>

#define maxValDsply 8 //Symbolic Constant that holds max value output for each line

using namespace std;

//Function Prototypes
void merge_sort(int[], int, int);
void merge( int[], int, int, int);
void printArray(int[], int);


int main()
{

//Variables:
int array[1000],//Array that can hold up to 1000 integer elements
    arraySize,//Integer that holds the number of elements in the array
    start = 0, //Integer that holds the first element of the array
    end = 0; //Integer thats holds the last element of the array

//Reading input for array
while(cin >> array[arraySize])
    {
        arraySize++;
    }

end = arraySize - 1;//Initializing end element for array

//Calling quick_sort function
merge_sort(array, start, end);

//Calling print function
printArray(array, arraySize);

return 0;
}


/*
Function: merge_sort
Use: To divide the array into two subarrays, sort them, and then merge them
Arguments: array[]: Holds an array of integers to be sorted
           start: An integer holding the first element value of the array
           end: An integer holding the last element value of the array
Returns:Nothing
Notes: None
*/
void merge_sort(int array[], int start, int end) //start = l, end = r, mid = m
{
      //Variable(s)
      int mid;//An integer to hold the element position where to split the array

      if (start < end) 
      {
        //Intializing the mid point of the array and sorting the sub-arrays
          mid = start + (end - start) / 2;

          merge_sort(array, start, mid);
          merge_sort(array, mid + 1, end);

         // Merge the sorted subarrays
          merge(array, start, mid, end);
      }
}


/*
Function: merge
Use: To merge two subarrays into original array
Arguments: array[]: Holds an array of integers to be merged back together
           start: An integer holding the first element value of the array
           end: An integer holding the last element value of the array
Returns: Nothing
Notes: None
*/
void merge(int array[], int start, int mid, int end) //start = p, mid = q, end = r
{
    //Initializing Varaiables for each sub-array:
    int n_Elements1 = mid - start + 1,//An integer to hold the amount of elements for the first sub-array
        n_Elements2 = end - mid,//An integer to hold the amount of elements for the second sub-array 
        //Initializing each sub-array
        subArr1[n_Elements1],//A sub-array of integers to hold the first half of the original array's elements
        subArr2[n_Elements2];//A sub-array of integers to hold the second half of the original array's elements

    //Looping through each sub-array to sort the elements in order
    for (int i = 0; i < n_Elements1; i++)
         subArr1[i] = array[start + i];

    for (int j = 0; j < n_Elements2; j++)
         subArr2[j] = array[mid + 1 + j];


    //Variables to hold sub-arrays indexes
    int i = 0,//An integer to hold the index value for the first sub-array 
        j = 0,//An integer to hold the index value for the second sub-array
        k = start;//An integer to hold the index value for the original array


    // A while loop to reach either end of either subArr1 or subArr2, then pick larger elements
    // within subArr1 and SubArr2 and place them in the correct position at array[start..mid]
    while (i < n_Elements1 && j < n_Elements2) 
    {
        if (subArr1[i] <= subArr2[j]) 
        {
            array[k] = subArr1[i];
            i++;
        } 

        else 
        {
            array[k] = subArr2[j];
            j++;
        }

        k++;
    }

    // Two while loops to pick up the remaining elements and put in array[start..end]
    while (i < n_Elements1) 
    {
        array[k] = subArr1[i];
        i++;
        k++;
    }

    while (j < n_Elements2) 
    {
        array[k] = subArr2[j];
        j++;
        k++;
    }
}


/*
Function: printArray
Use: To print out each value in the sorted array
Arguments: array[]: Holds an array of integers to be printed
           arraySize: An integer that holds the size of the array
Returns: Nothing
Notes: None
*/
void printArray(int array[], int arraySize)
{

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

}