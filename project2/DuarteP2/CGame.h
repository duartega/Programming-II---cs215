/*******************************************************************************
* Assignment: Project 2 - ASCII Move and Match Game                            *
* Author: Gabriel Duarte                                                       *
* Date: Fall 2017                                                              *
* File: CGame.h                                                                *
* Description: This file contains the instructions, display  prototype, moves  *
* the match, update, restart, done, and message prototypes.                    *
*******************************************************************************/

#ifndef CGAME_H
#define CGAME_H

#include <iostream>
using namespace std;

const bool testing = true;

/*******************************************************************************
* Type: sType                                                                  *
*                                                                              *
* Description: The sType enumerated type is used to identify the type of the   *
*              information stored in a CGameSquare object.                     *
*******************************************************************************/

enum sType {BORDER, ME, SYMBOL, EMPTY};

/*******************************************************************************
* Class: CGame                                                                 *
*                                                                              *
* Description: This class is designed to create all the variables needed.      *
*******************************************************************************/

class CGame
{
    public:
        CGame ();
        CGame (const CGame & other);
        ~CGame ();
        CGame & operator = (const CGame & other);
	void Init (int R, int C, int M);
        void Instructions (ostream & outs, istream & ins);
        void Display (ostream & outs);
        void Move (char direction);
        void Match ();
        void Update ();
        void Restart ();
	bool Done ();
        void Message (bool done, ostream & outs);
    private:
	struct CGameSquare
	{
		CGameSquare ();
		void Display (ostream & outs);
		void Fill ();
		sType what;
		int whichSymbol;
		bool matched;
		int value;
	};
        void FillIn ();
        CGameSquare ** grid;
        int numRows, numCols;
        int myRow, myCol;
	int movesLeft;
	int score;
};

#endif
