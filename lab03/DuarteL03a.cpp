// Assignment : Lab03a
// File : Words.txt
// Author : Gabriel Duarte
// Date : 9-10-17
// Description : This program should open a file, count the number of words
// vowels, consonants, and special characters.

#include <iostream>
#include <fstream>
using namespace std;

// Prototypes for funcitons used by this program
bool isvowel(char aletter);

int main()
{
  // Lets us open a file
  ifstream input;
  // Create a string variable
  string aword;
  // Open the file we point to
  input.open("words.txt");

  // Reads all the  words from the file
  while( input >> aword)
    {
      int lettercount = 0;
      int vowelcount = 0;
      int consonantcount = 0;
      int numcount = 0;
      int specialchars = 0;
      int i = 0;
      while (i<aword.length())
	{
	  if (isalpha(aword[i]))
	    lettercount++;
	  if (isvowel(aword[i]))
	    vowelcount++;
	  if (isvowel(aword[i]) == false && isalpha(aword[i]))
	    consonantcount++;
	  if (isdigit(aword[i]))
	    numcount++;
	  if (isvowel(aword[i]) == false && isalpha(aword[i]) == false && isalnum(aword[i]) == false)
	    specialchars++;
	  i++;
	}
      // Using the output operator to write the word and its length on a single line
      cout << aword << '\t' << aword.length()  << '\t' <<  vowelcount << '\t' << consonantcount << '\t' <<  numcount << '\t' << specialchars <<  endl;
    }
  return 0;
}

// Implementations for functions used by this program.

bool isvowel(char aletter)
{
  char upcase = toupper(aletter);
  if (upcase == 'A' || upcase == 'E' || upcase == 'I' || upcase == 'O' || upcase == 'U')
    return true;
  return false;
}
