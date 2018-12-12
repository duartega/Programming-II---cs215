// Assignment : Lab01
// File : DuarteLab01b.cpp
// Author : Gabriel Duarte
// Date : 8/24/17 Fall 2017
// Description : This program will request the user's name and write
// the message "Hello Name" on the standard console output screen.

// Include input and output stream and string libraries.
#include <iostream>
#include <string>
#include <cmath>
// Use the standard namespace.
// This will allow the program to write to cout and read from cin.
using namespace std;

// Prototype for function to ask the user for their name.
string GetName (ostream & outs, istream & ins);
// Prototype for function to print the message.
void PrintMessage (string message, ostream & outs);

int main()
{
  // Declare a string variable to hold the user's name.
  // Call GetName function to get the user's name and
  // store the returned value in the usersname.
  string usersname = GetName (cout, cin);
  // Create a message by concatenating hello and the user's name.
  string mymessage = "Hello " + usersname;
  // Call the PrintMessage function to print the message.
  PrintMessage (mymessage, cout);
  // Exit from the program.
  return 0;
}

// Function to ask the user for their name.
// The input stram and the output stream are passed to this
// function. This function will write a message requesting the
// user's name to the output stream. It will then read te user's
// name from the input stream and store it in a string variable.
// Finally, it will return the string.
string GetName (ostream & outs, istream & ins)
{
  // Declare a string variable to hold the user's name.
  string name;
  // Request the user's name.
  outs << "Please enter your name: " << endl;
  // Read the user's name from cin - the standard input - generally
  // the keyboard.
  ins >> name;
  return name;
}

// Function to print the message.
// THe message an the output stream are passed to this function.
// There is no returned value.
void PrintMessage (string message, ostream & outs)
{
  // Declare a variable for maxAngle and angle for 0 and 2pi.
  float maxAngle = 6.28;
 	// Declare a variable to count the lines as they are printed
  float angle = 0;
  
  while (angle < maxAngle)
  {
    // Increments by 0.3 every time so that the name (or space) is moved
    angle += 0.3;
    
    outs << "| ";
    // This is going to give the name a sine wave.
    int numSpaces = int(20 + 20 * sin(angle));
    // Decalre a variable to count the spaces as they are printed.
    int spaceCount = 0;
    
    // Declare the first loop to start writing the spaces
    while (spaceCount < numSpaces)
    {
      // Write a single space to outs.
      outs << ' ';
      // Increment the space counter.
      spaceCount++;
    }
    
    // Write the message to cout - the standard output - generally
    // the monitor.
    outs << message;

    // Resets the number of spaces and starts writing from the other side first
		numSpaces = int(20 + 20 * -(sin) (angle));
		// Resets the counter variable
		 spaceCount = 0;
		 
		 // Another loop to space and increment the number of spaces
		while (spaceCount < numSpaces)
		{
			// Write a single space to outs.
			outs << ' ';
			// Increment the line counter
			spaceCount++;
		}

		// Prints the middle line 
		outs << " | ";
		
		// Declare a variable to hold the desired number of spaces again!
		// But this time it will be for the cosine wave and not sine.
		numSpaces = int(20 + 20 * (cos)(angle));
		//Declare a variable to count the spaces as they are printed.
		spaceCount = 0;

		while (spaceCount < numSpaces)
		{
			// Write a single space to outs for the second curve
			outs << ' ';
			// Increment the line counter for the second curve
			spaceCount++;
		}
		outs << message;
	       	numSpaces = int(20 + 20 * -(cos)(angle));
		//Declare a variable to count the spaces as they are printed.
		spaceCount = 0;

		// Another loop so that we can add more spaces again
		while (spaceCount < numSpaces)
		{
			// Write a single space to outs.
			outs << ' ';
			// Increment the line counter
			spaceCount++;
		}

		outs << " |"  << endl;
	
		// Increments the counter
		
  }
}
