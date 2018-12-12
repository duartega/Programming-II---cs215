/*******************************************************************************
* Assignment: Project 2 - ASCII Move and Match Game                            *
* Author: Gabriel Duarte                                                       *
* Date: Fall 2017                                                              *
* File: CGame.cpp                                                              *
* Description: This file contains the grid, values, and button presses.        *
*******************************************************************************/

#include <cstdlib>
#include <cstdio>
#include <ctime>
#include "CGame.h"
#include <time.h>
#include <string.h>
CGame savedGame;


/*******************************************************************************
* Function: CGameSqure()                                                       *
*                                                                              *
* Parameters: None                                                             *
* Return value: None                                                           *
* Description: This function will set the values                               *
*******************************************************************************/

CGame::CGameSquare::CGameSquare ()
{
	what = BORDER;
	whichSymbol = 0;
	matched = false;
	value = 0;
}

/*******************************************************************************
* Function: Display(ostream & outs)                                            *
*                                                                              *
* Parameters: ostream & outs                                                   *
* Return value: None                                                           *
* Description: This function will set and draw the characters for the grid.    *
*******************************************************************************/

void CGame::CGameSquare::Display (ostream & outs)
{
  char achar = ' ';
	switch (what)
	{
		case BORDER:
			achar = 'X';
			break;
		case ME:
			achar = '*';
			break;
		case SYMBOL:
			if (whichSymbol == 1)
			  achar = '!';
			if (whichSymbol == 2)
			  achar = '@';
			if (whichSymbol == 3)
                achar = '#';
			if (whichSymbol == 4)
			  achar = '$';
			if (whichSymbol == 5)
			  achar = '%';
			if (whichSymbol == 6)
			  achar = '^';
			if (whichSymbol == 7)
			  achar = '&';
			break;
			
	        case EMPTY:
			achar = ' ';
			break;
	}
	if (matched)
	  outs << '-' << achar << '-';
	else
	  outs << ' ' <<  achar << ' ';
}

/*******************************************************************************
* Function: Fill()                                                             *
*                                                                              *
* Parameters: None                                                             *
* Return value: None                                                           *
* Description: This function will set a symbol randomly.                       *
*******************************************************************************/

void CGame::CGameSquare::Fill ()
{
  what = SYMBOL;
  whichSymbol = rand() % 7 + 1; // Randomly fill the grid from our provided symbols
}

/*******************************************************************************
* Function: CGame()                                                            *
*                                                                              *
* Parameters: None                                                             *
* Return value: None                                                           *
* Description: This function will create the grid and intialize some values.   *
*******************************************************************************/

CGame::CGame ()
{
  numRows = 1;
  numCols = 1;
  grid = new CGameSquare * [3];
  grid[0] = new CGameSquare [3];
  grid[1] = new CGameSquare [3];
  grid[2] = new CGameSquare [3];
  myRow = 0;
  myCol = 0;
  movesLeft = 0;
  score = 0;
  srand (time (NULL));
}

/*******************************************************************************
* Function: CGame (const CGame & other)                                        *
*                                                                              *
* Parameters: const CGame & other                                              *
* Return value: None                                                           *
* Description: This function will copy the grid for the restart                *
*******************************************************************************/

CGame::CGame (const CGame & other)
{
    // Set variables for other
    numRows = other.numRows;
    numCols = other.numCols;
    myRow = other.myRow;
    myCol = other.myCol;
    // This will create a new grid
    grid = new CGameSquare * [numRows+2];
    for (int i = 0; i < numRows+2; i++)
    {
        // This will create a new 2d array for the grid
        grid[i] = new CGameSquare [numCols+2];
        for (int j = 1; j <= numCols; j++)
        {
            // Sets each [i][j] to the other
            grid[i][j] = other.grid[i][j];
        }
    }
  
}


/*******************************************************************************
* Function: operator = (const CGame & other)                                   *
*                                                                              *
* Parameters: (const CGame & other)                                            *
* Return value: * this                                                         *
* Description: This function will aid in the copy constructor by overloading   *
*               the assignment operator.                                       *
*******************************************************************************/

CGame & CGame::operator = (const CGame & other)
{  
  if (this == &other)
    return * this;
    
  // Delete the old grid so that we do not run into the pointer just updating
  // and not actually copying correctly.
  for (int r = 0; r < numRows+2; r++)
    delete [] grid[r];
  delete [] grid;

    // Set variables to other
  numRows = other.numRows;
  numCols = other.numCols;
  myRow = other.myRow;
  myCol = other.myCol;
    // Reset the score and moves to 0 and 30
    score = 0;
    movesLeft = 30;
    
    // Create the new grid
    grid = new CGameSquare * [numRows+2];
    for (int i = 0; i < numRows+2; i++)
    {// This will create a new 2d array for the grid
        grid[i] = new CGameSquare [numCols+2];
    for (int j = 1; j <= numCols; j++)
    {
        // Sets each [i][j] to the other
        grid[i][j] = other.grid[i][j];
    }
    }
  
  return * this;
}

/*******************************************************************************
* Function: ~CGame()                                                           *
*                                                                              *
* Parameters: None                                                             *
* Return value: None                                                           *
* Description: This function will delete some parts of the grid.               *
*******************************************************************************/

CGame::~CGame ()
{
	for (int r = 0; r < numRows+2; r++)
		delete [] grid[r];
	delete [] grid;
}

/*******************************************************************************
* Function: Init (int R, int C, int M)                                         *
*                                                                              *
* Parameters: (int R, int C, int M)                                            *
* Return value: None                                                           *
* Description: This function will create the grid and set the values.          *
*******************************************************************************/

void CGame::Init (int R, int C, int M)
{
        numRows = R;
        numCols = C;
        grid = new CGameSquare * [numRows+2];
        for (int r = 0; r < numRows+2; r++)
            grid[r] = new CGameSquare [numCols+2];
        FillIn ();
        myRow = 1 + rand() % numRows;
        myCol = 1 + rand() % numCols;
        grid [myRow][myCol].what = ME;
        grid [myRow][myCol].whichSymbol = 0;
	movesLeft = M;
	score = 0;
	savedGame = *this;
}

/*******************************************************************************
* Function: Instructions (ostream & outs, istream & ins)                       *
*                                                                              *
* Parameters: (ostream & outs, istream & ins)                                  *
* Return value: None                                                           *
* Description: This function will display the instructions of the game.        *
*******************************************************************************/

void CGame::Instructions (ostream & outs, istream & ins)
{
    string message = "\nWelcome to Move 'n Match Version 1\n\n";
	message += "The goal of this game is to accumulate points by\n";
	message += "moving the 'O' to create matches of 3 or more\n";
	message += "squares with the same symbol in a row or column.\n\n";
	message += "Enter 'w', 'a', 's', or 'd' to move the 'O'\n";
	message += "up, left, down, and right respectively\n\n";
	message += "Enter 'm' to identify matches.\n";
	message += "Enter 'u' to remove the current matches and\n";
	message += "update the tiles.\n";
	message += "Enter 'r' to restart the game.\n";
	outs << message << endl;
}

/*******************************************************************************
* Function: Display (ostream & outs)                                           *
*                                                                              *
* Parameters: (ostream & outs)                                                 *
* Return value: None                                                           *
* Description: This function will create the boarder.                          *
*******************************************************************************/

void CGame::Display (ostream & outs)
{
	int r, c;
	outs << endl << "\nScore: " << score;
	outs << "     Moves Left: " << movesLeft << "\n\n";
	for (r = 1; r <= numRows; r++)
	  { // Create the borders for the grid
	    outs << "\n  +---+---+---+---+---+---+---+---+---+---+---+---+---+\n";
	    outs << "  |";
	    for (c = 1; c <= numCols; c++)
		  {
		    grid [r][c].Display (outs);
		    outs << "|"; // Make sure there is seperation of collums.
		  }
		
	}
	outs << "\n  +---+---+---+---+---+---+---+---+---+---+---+---+---+\n";
	outs << "\n";
}

/*******************************************************************************
* Function: Move (char direction)                                              *
*                                                                              *
* Parameters: (char direction)                                                 *
* Return value: None                                                           *
* Description: This function will make moves, match, update, and restart.      *
*******************************************************************************/

void CGame::Move (char direction)
{
	int row = myRow;
	int col = myCol;
	
	switch (direction)
	{
		case 'a': // moving left
		  {
        // This sets the bounds so that you do not go out of the grid and cause seg fault
        if (myCol == 1)
          {  
            myCol = 1;
            break;
          }
          else
          {// Moves and takes away a move
		        movesLeft -=1;
		        myCol -= 1;
		        swap(grid[myRow][myCol+1], grid[myRow][myCol]);		  
		        break;
          }
		  }
		  
		case 'w': // moving up
		  {
        // This sets the bounds so that you do not go out of the grid and cause seg fault
        if (myRow == 1)
          {
            myRow = 1;
            break;
          }
        else
          {  // Moves and takes away a move
		        movesLeft -=1;
		        myRow -= 1;
		        swap(grid[myRow+1][myCol], grid[myRow][myCol]);		  
		        break;
          }
		  }

		case 'd': // moving right
		  {
        // This sets the bounds so that you do not go out of the grid and cause seg fault
        if (myCol == 13)
          {
            myCol = 13;
            break;
          }
        else
          {// Moves and takes away a move
		        movesLeft -=1;
		        myCol += 1;
		        swap(grid[myRow][myCol-1], grid[myRow][myCol]);
		        break;
          }
		  }

		case 's': // moving down
		  {
        // This sets the bounds so that you do not go out of the grid and cause seg fault
        if (myRow == 9)
          {
            myRow = 9;
            break;
          }
        else
          {// Moves and takes away a move
		        movesLeft -=1;
		        myRow += 1;
		        swap(grid[myRow-1][myCol], grid[myRow][myCol]);
		        break;
          }
		  }
	        case 'm':
		  {// Call the match function
		    Match();
		    break;
		  }
    case 'r': // Resarting the game
    {// Call the restart function
      Restart();
      break;
    }
	
}
}

/*******************************************************************************
* Function: Match()                                                            *
*                                                                              *
* Parameters: None                                                             *
* Return value: None                                                           *
* Description: This function will find 3 matched in a row and then set the     *
* matched to true so that we can mark them so the user knows they're matched   *
*******************************************************************************/

void CGame::Match ()
{

	// This gets the matches going up and down
  for (int i = 1; i < numRows; i++)
    for (int j = 1; j < numCols; j++)
      if (grid[i][j].whichSymbol == grid[i+1][j].whichSymbol && 
      grid[i][j].whichSymbol == grid[i+2][j].whichSymbol && 
      grid[i+1][j].whichSymbol == grid[i+2][j].whichSymbol)
	{
	  grid[i][j].matched = true;
	  grid[i+1][j].matched = true;
	  grid[i+2][j].matched = true;
     score += 3;

// This makes sure that there is not double counting	
 if (grid[i][j].whichSymbol == grid[i+1][j].whichSymbol && grid[i][j].whichSymbol == grid[i+2][j].whichSymbol && grid[i+1][j].whichSymbol == grid[i+2][j].whichSymbol && grid[i][j].whichSymbol == grid[i+3][j].whichSymbol)
 score -= 2;

  }
  // This gets the matches going across
  else if (grid[i][j].whichSymbol == grid[i][j+1].whichSymbol && grid[i][j].whichSymbol == grid[i][j+2].whichSymbol && grid[i][j+1].whichSymbol == grid[i][j+2].whichSymbol)
  {
    grid[i][j].matched = true;
	  grid[i][j+1].matched = true;
	  grid[i][j+2].matched = true;
    score += 3;
    // This makes sure that there is not double counting
if (grid[i][j].whichSymbol == grid[i][j+1].whichSymbol && grid[i][j].whichSymbol == grid[i][j+2].whichSymbol && grid[i][j+1].whichSymbol == grid[i][j+2].whichSymbol && grid[i][j].whichSymbol == grid[i][j+3].whichSymbol)
 score -= 2;
  }
}


/*******************************************************************************
* Function: Update()                                                           *
*                                                                              *
* Parameters: None                                                             *
* Return value: None                                                           *
* Description: This function will replace the marked matches with new chars.   *
*******************************************************************************/

void CGame::Update ()
{  
  int row = myRow;
  int col = myCol;
  
    // This loop will run through each i and j in the grid and replace the matched
    // symbols with a random symbol, then set the grid[i][j] position of the
    // matched symbol to false.
  for (int i = 1; i <= numRows; i++)
    for (int j = 1; j <= numCols; j++)
      if (grid[i][j].matched == true)
        { 
          grid[i][j].whichSymbol = rand() % 7 + 1;
          grid[i][j].matched = false;
        }

}

/*******************************************************************************
* Function: Restart()                                                          *
*                                                                              *
* Parameters: None                                                             *
* Return value: *This                                                          *
* Description: This function will return the saved game                        *
*******************************************************************************/

void CGame::Restart ()
{
	*this = savedGame;
}

/*******************************************************************************
* Function: Message (bool done, ostream & outs)                                *
*                                                                              *
* Parameters: (bool done, ostream & outs)                                      *
* Return value: None                                                           *
* Description: This function will print a message when the game is done        *
*******************************************************************************/

void CGame::Message (bool done, ostream & outs)
{

	char buffer [30];
	sprintf (buffer, "Your score is: %d", score);
	string message = "Thanks for playing!!\n" + string(buffer);
	outs << message << endl;
}

/*******************************************************************************
* Function: Done()                                                             *
*                                                                              *
* Parameters: None                                                             *
* Return value: movesLeft                                                      *
* Description: This function will tell the program that it has ended           *
*******************************************************************************/

bool CGame::Done () 
{
	return movesLeft == 0;
}

// Replace this function with the function(s) used to generate your game
/*******************************************************************************
* Function: Fill()                                                             *
*                                                                              *
* Parameters: None                                                             *
* Return value: None                                                           *
* Description: This function will gill the grid and call FillIn()              *
*******************************************************************************/

void CGame::FillIn ()
{
	for (int r = 1; r <= numRows; r++)
		for (int c = 0; c <= numCols; c++)
			grid[r][c].Fill();
}
