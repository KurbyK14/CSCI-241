//***************************************************************************
//
//  file-name:queens.cpp
//  CSCI 241 Assignment:2
//
//  Created by: Jacob Kurbis (z1945650)
//
// Purpose: The purpose of this program is to build an 8 by 8 chessboard and 
//          have it output the placement of 8 queens that are not alligned 
//          with each other by column, row, and diagonally.
//***************************************************************************/


#include <iostream>

using namespace std;

//Symbolic Constant for 8 by 8 chessboard
#define N 8


//Queen Solver class
class queen_solver
{
//Data Members
private:

// 2D Array of Boolean Values 
bool board[N][N] = {{false}};

//Public Functions
public:

    queen_solver() = default; //Constructor
    bool place_queens();
    bool place_queen_in_row(int);
    bool is_safe(int, int) const;
    void print_solution() const;
};


int main()
{
//Declaring object q
    queen_solver q;

//Calling recursive function place_queens
    if (q.place_queens())
//Calling the print_solution function to print out the queens on the chess board    
        q.print_solution();
    else
        cout << "Error - no solution found\n";//Error printout in case program fails

    return 0;
}

/*
Function: place_queens
Use: This function places a queen in the first row
Arguments: None
Returns: returns a boolean value --> True or False
Notes: None
*/
bool queen_solver::place_queens()
{
//Calling place_queen_in_row to try to place the first queen in first row
    return place_queen_in_row(0);
}

 /*
Function: place_queen_in_row
Use: This function places a queen in the current row if it passes the restrictions 
Arguments: row- An integer that holds the value of the current row of the chessboard
Returns: returns a boolean value --> True or False
Notes: None
*/
bool queen_solver::place_queen_in_row(int row)
{
    // Base case #1 - All queens have been placed successfully.
    if (row >= 8)
        return true;

    for (int col = 0; col < N; col++)
    {
        if (is_safe(row, col))
        {
             board[row][col] = 1;

            if (place_queen_in_row(row + 1) == true)
               {
               	// Base case #2 - All queens in rows below this one
                // have been successfully placed.
                return true;
			   }
           else
               {
               	board[row][col] = 0;
			   }
        }
    }
 // Base case #3 - We were not able to place a queen anywhere in
    // this row.
    return false;
}

/*
Function: is_safe
Use: This constant function evaluates whether if a queen is able to be placed at the current chessboard location
Arguments: row- An integer that holds the value of the current row of the chessboard
           col- An integer that holds the value of the current col of the chessboard
Returns: returns a boolean value --> True or False
Notes: None
*/
bool queen_solver::is_safe(int row, int col) const
{

//Loop to determine if there's a queen in the rows above this column
    for (int i = 0; i < row; i++)
    {
        if (board[i][col])
        {
        return false;//Return a false value if placement on chessboard does not pass this loop test
        }
    }

//Loop to determine if there's a queen in the left diagonal above this row
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j])
        {
        return false;//Return a false value if placement on chessboard does not pass this loop test
        }
    }


//Loop to determine if there's a queen in the right diagonal above this row
    for (int i = row, j = col; i >= 0 && j < N; i--, j++)
    {
        if (board[i][j])
        {
        return false;//Return a false value if placement on chessboard does not pass this loop test
        }
    }

    return true;//Return a true value if placement on chessboard passes previous loop tests
}


/*
Function: print_solution
Use: This constant function prints the output of the solution to the Eight Queens problem
Arguments: None
Returns: Nothing
Notes: None
*/
void queen_solver::print_solution() const
{

//Variables
    int cnt = 0; //An integer counter to keep track of how many values are on each line of output

//Looping through 2D array values
    for ( int i = 0; i < N; i++)
    {
        for (int j= 0; j < N; j++)
        {
        cout << board[i][j] << " ";
        cnt++;
        if (cnt % 8 == 0)//If the counter has a remainder of 0, it will start a new line
           {
           cout << endl;
		   }
        }
    }
}
