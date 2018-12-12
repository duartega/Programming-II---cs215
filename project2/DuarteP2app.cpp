/*******************************************************************************
* Assignment: Project 2 - ASCII Move and Match Game                            *
* Author: Gabriel Duarte                                                       *
* Date: Fall 2017                                                              *
* File: DuarteP2app.cpp                                                        *
*                                                                              *
* Description: This file contains the original instructions and also watches   *
*              for any key presses that we provided code for.                  *
*******************************************************************************/

#include <iostream>
#include "SetLimits.h"
#include "CGame.h"
using namespace std;

/*******************************************************************************
* Function: main()                                                             *
*                                                                              *
* Parameters: None                                                             *
* Return value: 0                                                              *
* Description: This function will look out for any key presses and also makes  *
*              sure that we are wanting to quit or restart.                    *
*******************************************************************************/

int main ()
{
    SetLimits();
    char play = 'y';
    CGame game;
    game.Instructions (cout, cin);
    while (tolower (play) == 'y')
    {
      game.Init(7, 9, 10);
	game.Display (cout);
	bool finished = false, quitting = false;
	while (!finished && !quitting)
	{
		char key;
		cout << "Enter move (a = left, w = up, d = right, s = down)." << endl;
		cout << "Or enter m = match, u = update, r = restart, q = quit." << endl;
		cout << "Enter i to see the game instructions again: ";
		cin >> key;
		if (key == 'q')
			quitting = true;
		else if (key == 'm')
			game.Match ();
		else if (key == 'u')
			game.Update ();
		else if (key == 'r')
			game.Restart ();
		else if (key == 'i')
			game.Instructions (cout, cin);
		else
			game.Move(key);
		finished = game.Done();
		game.Display (cout);
	}
	game.Message (finished, cout);
	cout << "Would you like to play again (y/n)? ";
	cin >> play;
	cin.clear ();;
    }
    cout << endl;
    return 0;
}
