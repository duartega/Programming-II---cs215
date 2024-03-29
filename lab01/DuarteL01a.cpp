/*
	Gabriel Duarte
	Lab01a
	8/28/2017
	CS215
*/

// Include the use of cout and cin as well as alogorith
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	// Create the variables
	double integer, average, total;

	// Initialize the variables
	total = 0;
	integer = 0;

	// Creates the array and sets the number of values
	int arr[10];

	// Asks the user to enter 10 integers
	cout << "Please enter 10 integer values." << endl;
	cout << "Each value should be entered on a separate line:" << endl;
	// This is the loop to enter the numbers into the array
	for (int i = 0; i < 10; i++)
	{
		// Reads what was entered and stores it in the integer variable
		cin >> integer;
		// Adds each number entered into the array
		arr[i] = integer;
		// Gets the sum of the integers
		total += integer;
		// Gets the average of the integers
		average = total / 10;
	}

	// Displays the numbers entered
	cout << "The values you entered are: " << endl << "[";
	
	for (int j = 0; j < 10; j++)
	{
		cout << arr[j];
		if (j!=9)
		  {
		    for (int k = 0; k < 1; k++)
		      {
			cout << ", ";			
		      }
		  }
	}
	cout << "]" << endl;

	// Displays the total
	cout << "The total of your values is: " << total << endl;

	// Displays the average
	cout << "The average of your values is: " << average << endl;

	// Sorts and displays the sorted array
	sort(arr, arr + 10);

	cout << "The sorted values are: " << endl << "[";
	for (int m = 0; m < 10; m++)
	{
		cout << arr[m];

		if (m !=9)
		  {
		    for (int p = 0; p < 1; p++)
		      {
			cout << ", ";
		      }
		  }
	}
	cout << "]" << endl;

	// Exits the program when any key is pressed
	return 0;
}
