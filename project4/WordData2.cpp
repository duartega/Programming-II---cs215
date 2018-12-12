// Title : Lab4 WordData class implementation 
// Author : Spencer Greco

#include "WordData.h"
#include <cstring>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

// Function implimentations will be placed after this line 

WordData::WordData()
{ // The default constructor 
	word = new char [1];
	word[0] = '\0';
	length = 0;
	vowels = consonants = digits = specialchars = 0;
}

WordData::WordData (const WordData & OtherWord)
{

	word = new char [1+OtherWord.length];
	strcpy (word, OtherWord.word);
	length = OtherWord.length;
	vowels = OtherWord.vowels;
	consonants = OtherWord.consonants;
	digits = OtherWord.digits;
	specialchars = OtherWord.specialchars;
}


WordData::~WordData()
{
	delete [] word;
}


bool isvowel (char aletter)
{
	char upcase = toupper (aletter);
	if (upcase == 'A' || upcase == 'E' || upcase == 'I'
			|| upcase == 'O' || upcase == 'U')
		return true;
	return false;
}


void WordData::SetWord  (const string & InWord) // counts the vowels, consonants, digits, and specail characters
{

	delete [] word;
	length = InWord.length();
	word = new char [1+length];
	strcpy (word, InWord.c_str());
	vowels = consonants = digits = specialchars = 0;		
	for (int i = 0; i < strlen(word); i++)
		if (isalpha (word[i]))
			switch (toupper (word[i]))
			{
				case 'A': case 'E': case 'I':
				case 'O': case 'U':
					vowels++; break;
				default:
					consonants++;
			}
		else if (isdigit (word[i]))
			digits++;
		else 
			specialchars++;
}

string WordData::GetWord () const
{

	return word; 
}


void WordData::WriteData (ostream & outs) const
{

	outs << setw (15) << left << word;
	outs << setw (8) << right << vowels;
	outs << setw (8) << consonants;
	outs << setw (8) << digits;
	outs << setw (8) << specialchars;
}

int WordData::GetNumVowels () const // returns vowels 
{
	return vowels;
}


int WordData::GetNumConsonants () const // returns consonats 
{
	return consonants;
}

int WordData::GetNumDigits () const
{
	return digits;
}

int WordData::GetNumSpecialChars () const
{
	return specialchars;
}

bool WordData::operator > (const WordData & OtherWord) const // Orders letter from smallest to largest
{

	if (length > OtherWord.length) 
		return true;
	else if (length == OtherWord.length && word > OtherWord.word)
	{
		if (word > OtherWord.word)
			return true;
		else 
			return false;
	}

}


bool WordData::operator < (const WordData & OtherWord) const // Orders letter from smallest to largest
{
	if (length < OtherWord.length) 
		return true;
	if (length > OtherWord.length)
		return false;
	string one = word;
	for (int i =0; i < one.length(); i++)
		one[i] = tolower(one[i]);
	string two = OtherWord.word;
	for (int i = 0; i < two.length(); i++)
		two[i] = tolower(two[i]);
	return one < two;
}





WordData & WordData::operator = (const WordData & OtherWord)
{
	// Test for self-assignment. If this and the address of OtherWord
	// are the same, return the object referenced by this:
	if (this == &OtherWord)
		return * this;
	
	// Delete the existing word
	delete [] word;
	// Alocate space for the new word 
	word = new char [1+ OtherWord.length];
	// Copy the new word from OtherWord into word
	strcpy (word, OtherWord.word);
	length = OtherWord.length;

	//copy the remaining attributes of OtherWord into the 
	//corresponding attributes of this:
	vowels = OtherWord.vowels;
	consonants = OtherWord.consonants;
	digits = OtherWord.digits;
	specialchars = OtherWord.specialchars;

	// Return the object referenced by this:
	return * this;
}


bool WordData::operator == (const WordData & OtherWord) const 
{
	if (word == OtherWord.word)
		return true;
	else
		return false;
}

WordData WordData::operator + (const WordData & OtherWord) const
{
	char * temp = new char [1+length + OtherWord.length];
	strcpy (temp, word);
	strcat (temp, OtherWord.word);
	WordData sum(temp);
	return sum;
}


ostream & operator << (ostream & outs, const WordData & W)
{
	outs << setw(12) << left << W.word;
	outs << setw(8) << right << W.vowels;
	outs << setw(8) << right << W.consonants;
	outs << setw(8) << right << W.digits;
	outs << setw(8) << right << W.specialchars;
	return outs;

}


istream & operator >> (istream & ins, WordData & W)
{
	string astring = "";
	ins >> astring;
	if (!ins.fail())
		W.SetWord(astring);
	return ins;
}	

WordData::WordData(const string & InWord)
{
	word = NULL;
	SetWord(InWord);
}

