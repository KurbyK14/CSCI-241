//***************************************************************************
//
//  file-name:hanoi.cpp
//  CSCI 241 Assignment:2  
//
//  Created by: Jacob Kurbis (z1945650)
//
//  Purpose: A program to use a recursive function to solve the Towers of 
//           Hanoi Problem.
//
//***************************************************************************/

#include <iostream> 
#include <cstdlib>
#include <cctype>
#include <cstring>

using std::cout;
using std::endl;
using std::stoi;

//Function Prototype(s):
void moveDiscs( int, int, int, int);


int main(int argc, char* argv[] )
{

//Variables
int n_discs;//An integer to store the amount of discs to sort

//Reading and Testing if command-line input is a numeric value
if (argc == 1)
   {
//Outputting Error message if n_discs = 1
   cout << "Missing argument" << endl
        << "Usage: hanoi number_of_disks" << endl;
   exit(1);
   }
//Outputting Error message if command-line input is not a numeric value
for (int i = 0; argv[1][i] != '\0'; i++)
   {
   if (!isdigit(argv[1][i]))
     {
     cout << "Argument must be a number" << endl 
          << "Usage: hanoi number-of-disks" << endl;
     
     exit(1);
     }
   }

n_discs = stoi(argv[1]);

//Passing n_discs amount, and peg number values to the moveDiscs function 
moveDiscs(n_discs, 1, 2, 3);

return 0;
}

/*
Function: moveDiscs

Use: This function will tell the user what moves to make with each disc,
     it does not actually move anything.

Arguments:n_discs- An integer thats holds the number of total discs
          src_peg- An intger that holds the value of the source peg(1)
          dest_peg- An integer that holds the value of the destination
                    peg(2)
          temp_peg- An intger that holds the value of the temporary peg(3)

Returns: Nothing
Notes: None
*/
void moveDiscs(int n_discs, int src_peg, int dest_peg, int temp_peg)
{

//Checking if discs fall below or equal to 1
    if (n_discs >= 1)
    {
//First Recursive Call
    moveDiscs(n_discs - 1, src_peg, temp_peg, dest_peg);
//Output Instuction Step for User
    cout << n_discs << " " << src_peg
         << "->" << dest_peg << endl;
//Second Recursive Call
    moveDiscs(n_discs - 1, temp_peg, dest_peg, src_peg);
    }

}
