// Title: Lab 7 WordData class and implementation for Project 4
// Author : Gabriel Duarte
// Description : This is the header file
#include "WordData.h"

/*******************************************************************************
* Function: WordData()                                                         *
*                                                                              *
* Parameters: None                                                             *
* Return value: None                                                           *
* Description: This function will initialize the variables.                    *
*******************************************************************************/

WordData::WordData()
{
  word = new char [1];
  word[0] = '\0';
  length = 0;
  vowels = consonants = digits = specialchars = 0;
}

/*******************************************************************************
* Function: WordData (const WordData & OtherWord)                              *
*                                                                              *
* Parameters: const WordData & OtherWord                                       *
* Return value: None                                                           *
* Description: This function will set the other variables values.              *
*******************************************************************************/

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

/*******************************************************************************
* Function: WordData (cost string & InWord)                                    *
*                                                                              *
* Parameters: const string & InWord                                            *
* Return value: None                                                           *
* Description: This function will initialize the variable and set word.        *
*******************************************************************************/

WordData::WordData (const string & InWord)
{
  word = new char[1];
  word[0] = '\0';
  SetWord(InWord);
}

/*******************************************************************************
* Function: ~WordData()                                                        *
*                                                                              *
* Parameters: None                                                             *
* Return value: None                                                           *
* Description: This function will delete the words so we can free memory.      *
*******************************************************************************/

WordData::~WordData()
{
  if (word)
    delete [] word;
}

/*******************************************************************************
* Function: isvowel (char aletter)                                             *
*                                                                              *
* Parameters: char aletter                                                     *
* Return value: false                                                          *
* Description: This function will check to see if the letter is a vowel.       *
*******************************************************************************/

bool isvowel(char aletter)
{
  // Checks to see if there is a vowel and converts them to uppercase so you 
  // dont have to check for upper and lower, to make for more efficient code
  char upcase = toupper(aletter);
  if (upcase == 'A' || upcase == 'E' || upcase == 'I' || upcase == 'O' || upcase == 'U')
    return true;
  return false;
}

/*******************************************************************************
* Function: SetWord (const string & InWord)                                    *
*                                                                              *
* Parameters: string & InWord                                                  *
* Return value: None                                                           *
* Description: This function will copy the word and set its values.            *
*******************************************************************************/

void WordData::SetWord (const string & InWord)
{
if (testing)
  cout << "The SetWord has been called for this address: " << this << endl;
/*
will copy the word in InWord into the class object word variable
will count the vowels, consonants, digits, specialchars
*/
 delete [] word;
 length = InWord.length();
 word = new char [1+ length];
 strcpy (word, InWord.c_str());
 vowels = consonants = digits = specialchars = 0;
 for (int i = 0; i < strlen(word); i++)
   if (isalpha (word[i]))
     switch (toupper (word[i]))
       {
       case 'A': case 'E': case 'I': case 'O': case 'U':
	 vowels++; break;
       default:
	 consonants++;
       }
   else if (isdigit (word[i]))
     digits++;
   else
     specialchars++;
}

/*******************************************************************************
* Function: GetWord () const                                                   *
*                                                                              *
* Parameters: None                                                             *
* Return value: word                                                           *
* Description: This function will return the word as a c++ string.             *
*******************************************************************************/

string WordData::GetWord () const
{
if (testing)
  cout << "The GetWord has been called for this address: " << this << endl;
return word;
}

/*******************************************************************************
* Function: WriteData (ostream & outs)                                         *
*                                                                              *
* Parameters: ostream & outs                                                   *
* Return value: None                                                           *
* Description: This function will write the variable values to outs.           *
*******************************************************************************/

void WordData::WriteData (ostream & outs) const
{
if (testing)
  cout << "The WriteData has been called for this address: " << this << endl;
/*
  will write the value of word, left justified with 12 spaces
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

/*******************************************************************************
* Function: GetNumVowels () const                                              *
*                                                                              *
* Parameters: None                                                             *
* Return value: vowels                                                         *
* Description: This function will return the vowels                            *
*******************************************************************************/

int WordData::GetNumVowels() const
{ return vowels;
}

/*******************************************************************************
* Function: GetNumConsonants () const                                          *
*                                                                              *
* Parameters: None                                                             *
* Return value: consonants                                                     *
* Description: This function will return the consonants.                       *
*******************************************************************************/

int WordData::GetNumConsonants() const
{ return consonants;
}

/*******************************************************************************
* Function: GetNumDigits () const                                              *
*                                                                              *
* Parameters: None                                                             *
* Return value: digits                                                         *
* Description: This function will return the digits.                           *
*******************************************************************************/

int WordData::GetNumDigits() const
{ return digits;
}

/*******************************************************************************
* Function: GetNumSpecialChars () const                                        *
*                                                                              *
* Parameters: None                                                             *
* Return value: specialchars                                                   *
* Description: This function will return the specialchars.                     *
*******************************************************************************/

int WordData::GetNumSpecialChars() const
{ return specialchars;
}

/*******************************************************************************
* Function: operator > (cosnt WordData & OtherWord)                            *
*                                                                              *
* Parameters: const WordData & OtherWord                                       *
* Return value: false or true                                                  *
* Description: This function will check to see of the lengths are greater.     *
*******************************************************************************/

bool WordData::operator > (const WordData & OtherWord) const
{
  if (length > OtherWord.length)
    return true;
  else if (length == OtherWord.length && word >OtherWord.word)
    {
    if (word > OtherWord.word)
      return true;
    }
  else
    return false;
}

/*******************************************************************************
* Function: operator = (const WordData & OtherWord)                            *
*                                                                              *
* Parameters: const WordData & OtherWord                                       *
* Return value: *this                                                          *
* Description: This function will make copy the word from other word and then  *
*              cooy the attributes from OtherWord into corresponding attributes*
*******************************************************************************/

WordData & WordData::operator = (const WordData & OtherWord)
{
  // Test for self-assignment. If this and the address of OtherWord
  // are the same, return the object referenced by this:
  if (this == & OtherWord)
    return * this;

  // Delete the existing word
  delete [] word;
  // Allocate space for the new word
  word = new char [1+ OtherWord.length];
  // Copy the new word from OtherWord into word
  strcpy (word, OtherWord.word);
  length = OtherWord.length;
  
  // Copy the attributes of OtherWord into the corresponding
  // attributes of this:
 
  vowels = OtherWord.vowels;
  consonants = OtherWord.consonants;
  digits = OtherWord.digits;
  specialchars = OtherWord.specialchars;


  // Return the object referenced by this:
  return * this;

}

/*******************************************************************************
* Function: operator == (const WordData & OtherWord)                           *
*                                                                              *
* Parameters: const WordData & OtherWord                                       *
* Return value: true or false                                                  *
* Description: This function will compare the two strings.                     *
*******************************************************************************/

bool WordData::operator == (const WordData & OtherWord) const
{
  if (strcmp (word, OtherWord.word) == 0)
    return true;
  return false;
}

/*******************************************************************************
* Function: operator + (const WordData & OtherWord)                            *
*                                                                              *
* Parameters: const WordData & OtherWord                                       *
* Return value: sum                                                            *
* Description: This function will return the added attributes.                 *
*******************************************************************************/

WordData WordData::operator + (const WordData & OtherWord) const
{
  WordData sum;
  delete [] sum.word;

  sum.word = new char [1 + OtherWord.length + length];
  strcpy(sum.word, word);
  strcat(sum.word, OtherWord.word);
  sum.length = length + OtherWord.length;
  sum.vowels = vowels + OtherWord.vowels;
  sum.consonants = consonants + OtherWord.consonants;
  sum.digits = digits + OtherWord.digits;
  sum.specialchars = specialchars + OtherWord.specialchars;

  return sum;
}

/*******************************************************************************
* Function: operator << (ostream & outs, const WordData & W)                   *
*                                                                              *
* Parameters: ostream & outs, const WordData & W                               *
* Return value: outs                                                           *
* Description: This function will output the data to outs.                     *
*******************************************************************************/

ostream & operator << (ostream & outs, const WordData & w)
{
  outs << setw(12) << left << w.word;
  outs << setw(8) << right << w.vowels;
  outs << setw(8) << right << w.consonants;
  outs << setw(8) << right << w.digits;
  outs << setw(8) << right << w.specialchars;
  return outs;
}

/*******************************************************************************
 * Function: operator >> (istream & ins, WordData & w)                         *
*                                                                              *
* Parameters: istream & ins, WordData & w                                      *
* Return value: ins                                                            *
* Description: This function will return the words read in from the file.      *
*******************************************************************************/

istream & operator >> (istream & ins, WordData & w)
{
  string astring;

  ins >> astring;
  if (!ins.fail())
    w.SetWord(astring);
  return ins;
}

/*******************************************************************************
* Function: operator < (const WordData & OtherWord) const                      *
*                                                                              *
* Parameters: const WordData & OtherWord                                       *
* Return value: one < two                                                      *
* Description: This function will return the word smaller in length.           *
*******************************************************************************/

bool WordData::operator < (const WordData & OtherWord) const
{
  if (length < OtherWord.length)
    return true;
  if (length > OtherWord.length)
   return false;

  string one = word;

  for (int i = 0; i < one.length(); i++)
    one[i] = tolower(one[i]);

  string two = OtherWord.word;

  for (int i = 0; i < two.length(); i++)
    two[i] = tolower(two[i]);
return one < two;
}
