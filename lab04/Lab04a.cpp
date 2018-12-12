// Assignment : Lab03b
// File : words.txt
// Author : Gabriel Duarte
// Date : 9/10/2017
// Description : This program will show the words, sort them,
// get the totals for the vowels, consonants, specialchars,
// and numbers while displaying them in a nice fasion.

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

using namespace std;

// MAXWORDS contains the maximum number of words
const int MAXWORDS = 100;

// Definition of the worddata structure
struct worddata
{
  worddata ();
  string word;
  int vowels;
  int consonants;
  int digits;
  int specialchars;
};

// Initialize the values
worddata::worddata ()
{
  vowels = 0;
  consonants = 0;
  digits = 0;
  specialchars = 0;
}

// Prototype for functions used by this program
int ReadFile (ifstream & input, worddata Words[]);
void WriteReport (ostream & output, worddata Word[], int count);
void swap (worddata & a, worddata & b);
void WordSort (worddata Words[], int N);
bool isvowel(char aletter);

int main(int argc, char * argv[])
{
  // Declare an input file and opem .words.text.
  ifstream input ("words.txt");
  if (input.fail())
    {
      cout << "File: words.txt not found\n";
      exit (1);
    }

  // Declare an array of worddata objects to hold the words
  // and their vowel, consonant, digit, and special
  // from the file.
  worddata WordArray [MAXWORDS];

  // Call the ReadFile function to read the file, store the
  // words in the array and return the number of words read
  // from the file.
  int count = ReadFile (input, WordArray);
  cout << count << " words have been read from the file\n\n";

  // Call the WordSort function to sort the words into alpabetical order.
  WordSort (WordArray, count);

  // Call the WriteReport function to write the data
  // stored in the array in a formatted fashion.
  WriteReport (cout, WordArray, count);

  return 0;
}

// Implementations for functions used by this program

int ReadFile (ifstream & input, worddata Words[])
{
  int count = 0;
  while (input >> Words[count].word)
    {
      // Complete the following looping and decision code to
      // count the number of vowels, consonants, digits and,
      // special characters in the word and store them in
      // the object Words[count]

      for (int i = 0; i < Words[count].word.length(); i++)
	{
	  if (isalpha (Words[count].word[i]))
	    {
	      if (isvowel (Words[count].word[i]))
		{
		  Words[count].vowels++;
		}
		  else    
		    {
		      Words[count].consonants++;

		    }
	    }
	  // Gets and adds the totals for the specialchars
	  if (!isdigit (Words[count].word[i]) && !isalpha (Words[count].word[i]))
	    {
	    Words[count].specialchars++;
	    }
	        if (isdigit (Words[count].word[i]))
		  {
		    Words[count].digits++;
		  }
	}
      // Increment the counter
      count++;
    }
  input.close();
  // Return the totals
  return count;
}

void WriteReport (ostream & output, worddata Words[], int count)
{
  // Initialize the variables
  int totalvowels = 0, totalconsonants = 0;
  int totaldigits = 0, totalspecialchars = 0;

  // Set the columns as labels for the totals
  output << setw (12) << left << "Word";
  output << setw (8) << right << "Vowels";
  output << setw (8) << "Const.";
  output << setw (8) << "Digits";
  output << setw (8) << "Special" << endl;

  // Loop here to write the information about each word
  int i = 0;
  while (i < count)
    {
      // Write out the counts for each of the members
      output << setw (12) << left << Words[i].word;
      output << setw (8) << right << Words[i].vowels;
      output << setw (8) << Words[i].consonants;
      output << setw (8) << Words[i].digits;
      output << setw (8) << Words[i].specialchars << endl;

      // Get the totals for each of teh word vowelsand such
      totalvowels += Words[i].vowels;
      totalconsonants += Words[i].consonants;
      totaldigits += Words[i].digits;
      totalspecialchars += Words[i].specialchars;

      // Increment the counter      
      i++;
    }
  // Set the lines for the totals
  output << setw (12) << left << " ";
  output << setw (8) << right << "---";
  output << setw (8)  << "---";
  output << setw (8)  << "---";
  output << setw (8)  << "---" << endl;

  // Write the totals
  output << setw (12) << left << "Totals";
  output << setw (8)  << right << totalvowels;
  output << setw (8)  << totalconsonants;
  output << setw (8)  << totaldigits;
  output << setw (8)  << totalspecialchars << endl;
}

// Swap the current string
void swap (worddata & a, worddata & b)
{
  worddata temp;
  temp = a;
  a = b;
  b = temp;
}

// Sort the strings in order of the ascii chart
void WordSort (worddata Words[], int N)
{
  int i = 1;
  while (i < N)
    {
      int j = i;
      while (j > 0 && Words[j].word < Words[j-1].word)
	{
	  swap(Words[j], Words[j-1]);
	  j--;
	}
      i++;
    }
}

// Creates a function that allows you to count the vowels. 
bool isvowel(char aletter)
{
  char upcase = toupper(aletter);
  if (upcase == 'A' || upcase == 'E' || upcase == 'I' || upcase == 'O' || upcase == 'U')
    return true;
  return false;
}
