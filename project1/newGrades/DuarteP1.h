//
//
//
//
//
//

#ifndef GRADE
#define GRADE
#include <cstring>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

const bool testing = false;

class Grade
{
    public:
      Grade();
      Grade (const Grade & NewGrade);
      ~Grade(); // This is for the deconstructor
      void SetGType(char GRADETYPE); // This is for Grade Type(H, L, P, Q, T)
      void SetDate(const string & DATE); // This sets the date of the assignment
      void SetScore(float SCORE); // This sets the score they got
      void SetPossible(int POSSIBLE); // This sets the total possible
      void SetLetterGrade(char LETTER); // This sets the letter grade
      void SetTitle(const string & TITLE); // This sets the title of the class
      
      char GetGType() const; // This is for Grade Type(H, L, P, Q, T)
      string GetDate() const; // This sets the date of the assignment
      float GetScore() const; // This sets the score they got
      int GetPossible() const; // This sets the total possible
      char GetLetterGrade() const; // This sets the letter grade
      string GetTitle() const; //This gets the title of the class
      
      void WriteGradeData(ostream & output) const; // Writes the data out 
      bool operator < (const Grade & NewGrade);
      
    private:
      char gtype;
      string date;
      int possible;
      float score;
      char letter;
      string title;
};

Grade::Grade()
{// Constructor
  gtype;
  date = "";
  possible = 0;
  score = 0.0;
  letter;
  title = "";
}

Grade::Grade (const Grade & NewGrade)
{
if (testing)
  cout << "The copy constructor has been called for this address: " << this << endl;
  gtype = NewGrade.gtype;
  date = NewGrade.date;
  possible = NewGrade.possible;
  score = NewGrade.score;
  letter = NewGrade.letter;
  title = NewGrade.title;
}

Grade::~Grade()
{ // Deconstructor
}

void Grade::SetGType(char GRADETYPE)
{
	gtype = GRADETYPE;
}

void Grade::SetDate(const string & DATE)
{
	date = DATE;
}

void Grade::SetScore(float SCORE)
{
	score = SCORE;
}
 
void Grade::SetPossible(int POSSIBLE)
{
	possible = POSSIBLE;
}

void Grade::SetLetterGrade(char LETTER)
{
  int total = 0;
  char a = 'A';
  char b = 'B';
  char c = 'C';
  char d = 'D';
  char f = 'F';
  total = (score/possible)*100;
  if (total >= 90)
  letter = a;
  if (total < 90 && total >= 80)
  letter = b;
  if (total < 80 && total >= 70)
  letter = c;
  if (total < 70 && total >= 60)
  letter = d;
  if (total < 60)
  letter = f;
  
}

void Grade::SetTitle(const string & TITLE)
{
	title = TITLE;
}

char Grade::GetGType() const
{
	return gtype;
}

string Grade::GetDate() const
{
	return date;
}
float Grade::GetScore() const
{
	return score;
}

int Grade::GetPossible() const
{
	return possible;
}

char Grade::GetLetterGrade() const
{
	return letter;
}

string Grade::GetTitle() const
{
	return title;
}

void Grade::WriteGradeData(ostream & output) const
{
	output << setw(5) << left << gtype;
	output << setw(5) << date;
	output << setw(10) << right << score;
	output << setw(10) << right << possible;
	output << setw(8) << right << letter;
	output << setw(2) << left << ' ' << title;
}

bool Grade::operator < (const Grade & NewGrade)
{
  if (gtype < NewGrade.gtype)
    if (gtype > NewGrade.gtype && date < NewGrade.date)
      return true;
  return false;
}

#endif
