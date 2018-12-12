// Title: Lab 6 WordData class and implementation
// Author : Gabriel Duarte
// Description : This is the header file

#ifndef WORDDATA
#define WORDDATA
#include <cstring>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

const bool testing = false;

class WordData
{
      public:
            WordData();
            WordData (const WordData & OtherWord);
	    WordData (const string & InWord);
            ~WordData ();
            void SetWord (const string & InWord);
            string GetWord () const;
            void WriteData (ostream & outs) const;
            
            int GetNumVowels() const;
            int GetNumConsonants() const;
            int GetNumDigits() const;
            int GetNumSpecialChars() const;
            bool operator > (const WordData & OtherWord) const;

	    WordData & operator = (const WordData & OtherWord);
	    bool operator == (const WordData & OtherWord) const;
	    WordData operator + (const WordData & OtherWord) const;
	    friend istream & operator >> (istream & ins, WordData & w);
	    friend ostream & operator << (ostream & outs, const WordData & w);
	    bool operator < (const WordData & OtherWord) const;
	    
   private:
            char * word; // C++ string to hold the word
	    int length;
	    int vowels; // vowel counter
            int consonants; // consonant counter
            int digits; // digits counter
            int specialchars; // specialchars counter
};
#endif
