// Title: Lab 7 WordData class and implementation for Project 4
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
            ~WordData ();
            string GetWord () const;
            int GetNumVowels() const;
            int GetNumConsonants() const;
            int GetNumDigits() const;
            int GetNumSpecialChars() const;
	    WordData & operator = (const WordData & OtherWord);
	    bool operator == (const WordData & OtherWord) const;
	    bool operator < (const WordData & OtherWord) const;
	    WordData operator + (const WordData & OtherWord) const;
	    friend istream & operator >> (istream & ins, WordData & w);
	    friend ostream & operator << (ostream & outs, const WordData & w);
            void SetWord (const string & InWord);
            void WriteData (ostream & outs) const;

	    WordData (const string & InWord);  
            bool operator > (const WordData & OtherWord) const;

	    
   private:
            char * word; // C++ string to hold the word
	    int vowels; // vowel counter
            int consonants; // consonant counter
            int digits; // digits counter
            int specialchars; // specialchars counter

	    int length;
};
#endif
