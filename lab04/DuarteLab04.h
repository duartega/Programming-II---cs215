// Title: Lab 4 WordData class and implementation
// Author : Gabriel Duarte
// Description : This is the header file

#ifndef WORDDATA
#define WORDDATA
#include <cstring>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class WordData
{
    public:
            WordData();
            WordData (const WordData & OtherWord);
            ~WordData ();
            void SetWord (const string & InWord);
            string GetWord () const;
            void WriteData (ostream & outs) const;
    private:
            string word; // C++ string to hold the word
            int vowels; // vowel counter
            int consonants; // consonant counter
            int digits; // digits counter
            int specialchars; // specialchars counter
};

// Function implementation will be places after this line

WordData::WordData()
{
	vowels = 0;
	consonants = 0;
	digits = 0;
	specialchars = 0;
}

WordData::WordData (const WordData & OtherWord)
{
// Will copy the word from OtherWord and copy the counters from OtherWord---------------------------------------------
word = OtherWord.word;
vowels = OtherWord.vowels;
consonants = OtherWord.consonants;
digits = OtherWord.digits;
specialchars = OtherWord.specialchars;
}

WordData::~WordData()
{
// Leave blank
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

void WordData::SetWord (const string & InWord)
{
/*
will copy the word in InWord into the class object word variable
will count the vowels, consonants, digits, specialchars
*/

word = InWord;
for (int i = 0; i < word.length(); i++)
		{
			if (isalpha(word[i]))
			{
				if (isvowel(word[i]))
				{
					vowels++;
				}
				else
        {
					consonants++;
				}
			}
			else if (isdigit(word[i]))
			  digits++;
			else
			{
				specialchars++;
			}    
		}

}

string WordData::GetWord () const
{
/*
will return the word as a c++ string
*/
return word;
}

void WordData::WriteData (ostream & outs) const
{
/*
will wirte the value of word, left justified with 12 spaces
will write the counter values each right justified and 8 spaces
no new line at the end
*/
	// Write out the counts for each of the members
    outs << setw (15) << left << word;
		outs << setw (8) << right << vowels;
		outs << setw (8) << consonants;
		outs << setw (8) << digits;
		outs << setw (8) << specialchars;
}



#endif