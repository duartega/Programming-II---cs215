/*
Assignment : Lab04b
File : Words.txt
Author : Gabriel Duarte
Date : 9/18/2017
Description : We are reading things from a file, organizing them in alphabetical order 
			  as well as getting the amount of vowels, cons, digits, and special chars but this time
             using functions and a struct.
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <string>

// Allows us to use the standard input and output stream
using namespace std;

// Definition of the worddata structure
struct worddata
{
	worddata();
	string word;
	int vowels;
	int consonants;
	int digits;
	int specialchars;
};

// Prototypes for functions used by this program
int ReadFile(ifstream & input, worddata * & Words);
void WriteReport(ostream & output, worddata Words[], int count);
void swap(worddata & w1, worddata & w2);
void WordSort(worddata words[], int N);
bool isvowel(char aletter);

int main (int argc, char * argv [] )
{
	// Check to see if the user entered an input file name
	// Exit if no file name
	if (argc < 2)
	{
		cout << "Usage: " << argv[0] << " words.txt\n";
		exit(1);
	}

	// Declare and open an input file
	ifstream input(argv[1]);

	// Check to see if the file was successfully opened 
	// Exit if no file found
	if (input.fail())
	{
		cout << "File: " << argv[1] << " not found\n";
		exit(2);
	}
 
  // Check to see if the user entered an input file name
	// and an output file name. Exit if no file name
	if (argc < 3)
	{
		cout << "Usage: " << argv[0] << " <words.txt> <out.txt>\n";
		exit(1);
	}

	// Open the output file
	ofstream output(argv[2]);

	// Check to see if the output file was successfully opened
	// Exit if the file could not be opened
	if (output.fail())
	{
		cout << "File: " << argv[2] << " could not be opened\n";
		exit(3);
	}

  // Declare a pointer to an arrat of worddata objects to
  // hold the words and their vowel, consonant, digit, and special character counts
  worddata * WordArray;

	// Call the ReadFile function to read the file, store the words in the array and return
	// the array and return the number of words read from the file
	int count = ReadFile(input, WordArray);

	// Lets you know how many words were read from the file
	cout << count << " words read from the file\n";

	// Call the WriteReport function to write the data stored in the array in a formatted fashion
	WriteReport(output, WordArray, count);

	// Call the WordSort function to sort the words into alpabetical order
	WordSort(WordArray, count);

	// Call the WriteReport function to write the data stored in the array in a formatted fashion
	WriteReport(output, WordArray, count);

	// CLose the input file
	input.close();
 
 // Close the outpout file
	output.close();
	
	// Exits the program
	return 0;
}

// Implementations for functions used by this program

// Defines the variables that were created in the worddata struct 
worddata::worddata()
{
	vowels = 0;
	consonants = 0;
	digits = 0;
	specialchars = 0;
}

// Reads the information that is in the file
int ReadFile(ifstream & input, worddata * & Words)
{
	// Initialize the variable
	int count = 0;
 string oneword;

 // Read and count the words in the file
 while (input >> oneword)
 count++;
 
 // Allocate space for the nu,ber of words counted by the previous loop
 Words = new worddata [count];
  
 
 // Clear the fail flag
 input.clear();
 
 // Reposition the file pointer to the beginning of the file
 input.seekg (0, ios::beg);
 count = 0;
 
    Words[count].vowels = Words[count].consonants = 0;
    Words[count].digits = Words[count].specialchars = 0;
  
    
	// Input the words into the Words array into the .word member
	while (input >> Words[count].word)
	{
		// Inputs the number of vowels, consonants, special chars, and digits in the correct
		// Member and adds their totals
		for (int i = 0; i < Words[count].word.length(); i++)
		{
			if (isalpha(Words[count].word[i]))
			{
				if (isvowel(Words[count].word[i]))
				{
					Words[count].vowels++;
				}
				else{
					Words[count].consonants++;
				}
			}
			else if (isdigit(Words[count].word[i]))
			  Words[count].digits++;
			else
			{
				Words[count].specialchars++;
			}    
		}
		count++;
   
	} 

	// Close the file
	input.close();

	// Returns the counts for each variable 
	return count;
}

void WriteReport(ostream & output, worddata Words[], int count)
{
	// Initialize the totals
	int totalvowels = 0, totalconsonants = 0;
	int totaldigits = 0, totalspecialchars = 0;

	// Set the columns as labels for the totals
	output << setw (15) << left << "Words";
	output << setw (8) << right << "Vowels";
	output << setw (8) << "Const.";
	output << setw (8) << "Digits";
	output << setw (8) << "Special" << endl;

	// Loop here to write information about each word
	int i = 0;
	while (i < count)
	{
		// Write out the counts for each of the members
   output << setw (15) << left << Words[i].word;
		output << setw (8) << right << Words[i].vowels;
		output << setw (8) << Words[i].consonants;
		output << setw (8) << Words[i].digits;
		output << setw (8) << Words[i].specialchars << endl;

		// Get the totals for each of the words vowels and such
		totalvowels += Words[i].vowels;
		totalconsonants += Words[i].consonants;
		totaldigits += Words[i].digits;
		totalspecialchars += Words[i].specialchars;

		// Increment so that it can go through each word
		i++;
	}
	
	// Set the lines for the totals
  output << setw(23) << "---";
  output << setw(8) << "---";
  output << setw(8) << "---";
	output << setw(8) << "---" << endl;

	// Write the totals
	output << setw (15) << left << "Totals";
	output << setw (8) << right << totalvowels;
	output << setw (8) << totalconsonants;
	output << setw (8) << totaldigits;
	output << setw (8) << totalspecialchars << endl;
}

// Swaps the words to make them rearrange in alphabetical order
void swap(worddata & w1, worddata & w2)
{
	worddata temp = w1;
	w1 = w2;
	w2 = temp;
}

// Swaps the words to make them rearrange in alphabetical order
void WordSort(worddata words[], int N)
{
	int i = 1;
	while (i < N)
	{
		int j = i;
		while (j > 0 && words[j].word < words[j - 1].word)
		{
			swap(words[j], words[j - 1]);
			j--;
		}
		i++;
	}
}

bool isvowel(char aletter)
{
	// Checks to see if there is a vowel and converts them to uppercase so you 
	// dont have to check for upper and lower, to make for more efficient code
	char upcase = toupper(aletter);
	if (upcase == 'A' || upcase == 'E' || upcase == 'I' || upcase == 'O' || upcase == 'U')
		return true;
	return false;
}

