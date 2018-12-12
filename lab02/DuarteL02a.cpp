// Program : Lab 2
// Description : This program will be used to explore how c++ handles
// Input and output for various data types.

// Three data values will be read from the standard input stream
// Results will be written to the standard output stream

#include <iostream>

// cin and cout will be used
using namespace std;

int main()
{
  // The variable, v, will be used to store the current input value
string v;

  cout << "Enter the data set input: ";

  for (int i = 1; i <= 3; i++)
    {
      cin >> v;
      cout << "The input value is " << v << "; the fail flag is ";
      if (cin.fail() == true)
	{
	  cout << "true" << endl;
	}
      else
	{
	  cout << "false" << endl;
	}
    }
  return 0;
}
