// Lab 08
// File : Lab08b.cpp
// Author : Dr. Watts
// Date : Spring 2014
// Description: This application program will be used to test the Shape class
// and its child classes: Square, Circle, EquiTri, Rectangle, and Triangle

#include <iostream>
#include <vector>
#include "Square.h"
#include "Circle.h"
#include "EquiTri.h"

using namespace std;

int main ()
{
	vector <Square *> mySquares;
	vector <Circle *> myCircles;
	vector <EquiTri *> myEquiTris;
	char which = ' ';
	do 
	{
		float len = 0;
		cout << "Enter S to create a Square\n";
		cout << "Enter C to create a Circle\n";
		cout << "Enter E to create an Equilateral Triangle\n";
		cout << "Enter Q to quit\n";
		cin >> which;
		switch (which)
		{
			case 'S': case 's':
			{
				cout << "Enter the length of the side of your square: ";
				cin >> len;
				Square * S = new Square (len);
				mySquares.push_back (S);
				break;
			}
			case 'C': case 'c':
			{
				cout << "Enter the length of the diameter of your circle: ";
				cin >> len;
				Circle * C = new Circle (len);
				myCircles.push_back (C);
				break;
			}
			case 'E': case 'e':
			{
				cout << "Enter the length of the side of your equilateral triangle: ";
				cin >> len;
				EquiTri * E = new EquiTri (len);
				myEquiTris.push_back (E);
				break;
			}
			case 'Q': case 'q':
				cout << "Thank you\n";
		}
	} while (toupper (which) != 'Q');
	for (int i = 0; i < mySquares.size(); i++)
		cout << *mySquares[i] << endl;
	for (int i = 0; i < myCircles.size(); i++)
		cout << *myCircles[i] << endl;
	for (int i = 0; i < myEquiTris.size(); i++)
		cout << *myEquiTris[i] << endl;
	return 0;
}
