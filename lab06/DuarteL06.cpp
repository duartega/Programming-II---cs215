// Title: Lab 6 WordData class and implementation
// Author : Gabriel Duarte
// Description : This is the header file
#include "DuarteL06.h"

// Function implementation will be places after this line

WordData::WordData()
{
  word = "";
  vowels = consonants = digits = specialchars = 0;}

WordData::WordData (const WordData & OtherWord)
{
  if (testing)
    cout << "The copy constructor has been called for this address: " << this << endl;
  // Will copy the word from OtherWord and copy the counters from OtherWord---------------------------------------------
  word = OtherWord.word;
  vowels = OtherWord.vowels;
  consonants = OtherWord.consonants;
  digits = OtherWord.digits;
  specialchars = OtherWord.specialchars;
}

WordData::~WordData()
{
  if (testing)
    cout << "The destructor has been called for this address: " << this << endl;
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
  if (testing)
    cout << "The SetWord has been called for this address: " << this << endl;
  /*
    will copy the word in InWord into the class object word variable
    will count the vowels, consonants, digits, specialchars
  */

  word = InWord;
  vowels = 0;
  consonants = 0;
  digits = 0;
  specialchars = 0;
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
  if (testing)
    cout << "The GetWord has been called for this address: " << this << endl;
  /*
    will return the word as a c++ string
  */
  return word;
}

void WordData::WriteData (ostream & outs) const
{
  if (testing)
    cout << "The WriteData has been called for this address: " << this << endl;
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

int WordData::GetNumVowels() const
{ return vowels;
}

int WordData::GetNumConsonants() const
{ return consonants;
}

int WordData::GetNumDigits() const
{ return digits;
}

int WordData::GetNumSpecialChars() const
{ return specialchars;
}

bool WordData::operator > (const WordData & OtherWord) const
{
  if (word.length() > OtherWord.word.length())
    return true;
  else if (word.length() == OtherWord.word.length() && word > OtherWord.word)
    return true;
  else
    return false;
}


WordData & WordData::operator = (const WordData & OtherWord)
{
  // Test for self-assignment. If this and the address of OtherWord
  // are the same, return the object referenced by this:
  if (this == & OtherWord)
    return * this;

  // Copy the attributes of OtherWord into the corresponding
  // attributes of this:
  word = OtherWord.word;
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
  WordData sum;
  sum.word = word + OtherWord.word;
  sum.vowels = vowels + OtherWord.vowels;
  sum.consonants = consonants + OtherWord.consonants;
  sum.digits = digits + OtherWord.digits;
  sum.specialchars = specialchars + OtherWord.specialchars;
  return sum;
}

ostream & operator << (ostream & outs, const WordData & w)
{
  outs << setw(12) << left << w.word;
  outs << setw(8) << right << w.vowels;
  outs << setw(8) << right << w.consonants;
  outs << setw(8) << right << w.digits;
  outs << setw(8) << right << w.specialchars;
  return outs;
}

istream & operator >> (istream & ins, WordData & w)
{
  string astring;

  ins >> astring;
  if (!ins.fail())
    w.SetWord(astring);
  return ins;
}
