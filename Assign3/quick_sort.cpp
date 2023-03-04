//***************************************************************************
//
//  quick_sort.cpp
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
void quick_sort(int[], int, int);
int partition( int[], int, int);
void printArray(int[], int);


int main()
{

//Variables:
int array[1000],//Array that can hold up to 1000 integer elements
    arraySize,//Integer that holds the number of elements in the array
    start = 0,//Integer that holds the first element of the array
    end = 0; //Integer thats holds the last element of the array

//Reading input for array
while(cin >> array[arraySize])
    {
        arraySize++;
    }

end = arraySize - 1;//Initializing end element for array

//Calling quick_sort function
quick_sort(array, start, end);

//Calling print function
printArray(array, arraySize);

return 0;
}


/*
Function: quick_sort
Use: A recursive function using the quick sort algorithm to sort an array of integers
Arguments: array[]: Holds an array of integers to be sorted
           start: An integer holding the first element value of the passed-in array
           end: An integer holding the last element value of the passed-in array
Returns:Nothing
Notes: None
*/
void quick_sort(int array[], int start, int end)
{
		
    //Quick Sort Algorithm	
    if (start < end)
    {
        int pivot_point = partition(array, start, end);
        quick_sort(array, start, pivot_point - 1);
        quick_sort(array, pivot_point + 1, end);
	}  
}


/*
Function: partition
Use: To partition an array into sub-arrays and sort them
Arguments: array[]: Holds an array of integers to be sorted
           start: An integer holding the first element value of the array
           end: An integer holding the last element value of the array
Returns: An integer, the pivot value for the quick_sort algorithm
Notes: None
*/
int partition(int array[], int start, int end)
{
    //Variables:
    int mid,//An integer to hold the value of the middle element of the array
        pivot_index,//An integer to store the first element of the array; the pivot_index for the quick_sort algorithm
        pivot_value,//An integer to hold the array's first element value; the pivot_value of the pivot_index
        scan;//An integer used as a way to scan the array for array values less than 
    
    mid = ((start + end ) / 2);//Setting mid to equal the middle element of the array

    //Swapping the start element with the mid element of the array
    int temp = array[start];
        array[start] = array[mid];
        array[mid] = temp;
    
    //Initializing Varaiables
    pivot_index = start;
    
    pivot_value = array[start];
    
    scan = start + 1;
    
    //Start While Loop to scan for lesser values 
    while (scan <= end)
    {
    	if (array[scan] < pivot_value)
    	{
    		pivot_index++;
            
            //Swapping the pivot_index value with the scan value
    		temp = array[pivot_index]; 
            array[pivot_index] = array[scan];
            array[scan] = temp;
		}
		
		scan++;
	}
	//Swapping the start element with the pivot_index element of the array
	temp = array[start]; 
    array[start] = array[pivot_index];
    array[pivot_index] = temp;

	
    return pivot_index;		
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