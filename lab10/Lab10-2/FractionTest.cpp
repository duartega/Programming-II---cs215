#include <iostream>
#include <fstream>
#include "LList2.hpp"
#include "Fraction.h"

using namespace std;

// Add a global variable for holding the sum of the fractions here
// Add a helper function prototype here

int main ()
{
	ifstream input ("Lab11.in");
	fraction one;
	LList2 <fraction> FL;
	while (input >> one)
		FL.InsertLast (one);
	cout << "The fractions are: ";
	cout << FL << endl;

	// Add code to find the sum of the fractions in the list FL here. 
	// You will need to use either the Forward or the Backward function
	// and a helper function.
 
	// Add code to print the sum here

	return 0;
}

// Add the helper function implementation here
