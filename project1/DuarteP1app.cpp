// Gabriel Duarte 
// cs215f17
//
//
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include "DuarteP1.h"

// Allows us to use the standard input and output stream
using namespace std;

const int MAXGRADES = 100;

int ReadFile(ifstream & input, Grade GArray[]);
//float WriteReport(ostream & output, const string & title, Grade GArray[], int first, int last, int count);
float WriteReport(const string & title, Grade GArray[], int first, int last, int count);
void Swap(Grade & a, Grade & b);
void WordSort(Grade GArray[], int N);

int main(int argc, char * argv[])
{
  Grade GradeArray[MAXGRADES];

  // Declare and open an input file
  ifstream input("grades.txt");
 
	if (input.fail())
	{
		cout << "File: " << argv[1] << " not found\n";
		exit(2);
	}   

	ofstream output(argv[2]);
 
	if (output.fail())
	{
		cout << "File: " << argv[2] << " could not be opened\n";
		exit(3);
	}
 
 	int count = ReadFile(input, GradeArray);
	count -=1;
	Grade g;
	string title = g.GetTitle();	
	int first = 0;
	int last = 1;
	WriteReport(title, GradeArray, first, last, count);

	WordSort(GradeArray, count);
	first = 2;
	last = 3;
	WriteReport( title, GradeArray, first, last, count);

	input.close();
 
	output.close();

  return 0;
}

// Reads the information that is in the file
int ReadFile(ifstream & input, Grade GArray[])
{
  // Initialize the variable
  int count = 0;   
  char GType;
  string date; 
  float score = 0;
  int possible = 0;
  string title;
  int total = 0;
  char letter;
  
  while(!input.eof())
    {
      input >> GType;
      GArray[count].SetGType(GType);
      input >> date;
      GArray[count].SetDate(date);
      input >> score;
      GArray[count].SetScore(score);
      input >> possible;
      GArray[count].SetPossible(possible);
      getline(input, title);
      GArray[count].SetTitle(title);  
      total = score/possible;
      GArray[count].SetLetterGrade(letter);
      count++;
    }
  input.close();
  return count;
}

float WriteReport( const string & title, Grade GArray[], int first, int last, int count)
{
float overallscore = 0, overalltotal = 0, overallgrade = 0, totalpercentage = 0;;
if (first ==0){
//_______________________________________________________________________________
  cout << "All Grades Report" << endl;
  cout << setw (5) << left << "Type";
  cout << setw (5) << "Date";
  cout << setw (10) << right << "Score";
  cout << setw (10) << right << "Possible";
  cout << setw (8) << right << "Grade";
  cout << setw (50) << left << "   Title" << endl;
  
  float totalscore = 0, totalpossible = 0;
  float percentage = 0;
  char grade;
  
  // Loop here to write each element
  int i = 0;
  // int count = 8;
  int score = 0;

      while (i < count)
	{
	  GArray[i].WriteGradeData(cout);
	  cout << endl;
	  totalscore += GArray[i].GetScore();
	  totalpossible += GArray[i].GetPossible();
	  i++;
	}
 cout << setw (20) << right << "---";
 cout << setw (10) << "---" << endl;
 cout << setw(20) << totalscore;
 cout << setw(10) << totalpossible << endl;
 percentage = (totalscore/totalpossible)*100;
 overallscore += totalscore;
 overalltotal += totalpossible;
 cout << "All grades percentage: "  << setprecision(3) << percentage << "%" << endl << endl;
 }
//_________________________________________________________________________________
if (last ==3){
  cout << "Homework and Labs Report" << endl;
  cout << setw (5) << left << "Type";
  cout << setw (5) << "Date";
  cout << setw (10) << right << "Score";
  cout << setw (10) << right << "Possible";
  cout << setw (8) << right << "Grade";
  cout << setw (50) << left << "   Title" << endl;
 int i = 0;
 // int count = 8;
 char h = 'H';
 char l = 'L';
 float totalscore = 0, totalpossible = 0;
 float percentage = 0;

 while (i < count)
	{
	  if (GArray[i].GetGType() == h || GArray[i].GetGType() == l)
	    {
	      GArray[i].WriteGradeData(cout);
	      cout << endl;
	      totalscore += GArray[i].GetScore();
	      totalpossible += GArray[i].GetPossible();
	    }	
     	i++;
	}
 cout << setw (20) << right << "---";
 cout << setw (10) << "---" << endl;
 cout << setw(20) << totalscore;
 cout << setw(10) << totalpossible << endl;
 percentage = (totalscore/totalpossible)*100;
 overallscore += totalscore;
 overalltotal += totalpossible;
 totalpercentage += percentage*.2;
 cout << "Homework and Labs percentage: " << setprecision(3) << percentage << "%" << endl << endl;
 //_________________________________________________________________________________  
  cout << "Projects Report" << endl;
  cout << setw (5) << left << "Type";
  cout << setw (5) << "Date";
  cout << setw (10) << right << "Score";
  cout << setw (10) << right << "Possible";
  cout << setw (8) << right << "Grade";
  cout << setw (50) << left << "   Title" << endl;
  i = 0;
  char p = 'P';
  totalscore = 0;
  totalpossible = 0;
  percentage = 0;
  while (i < count)
	{
    if (GArray[i].GetGType() == p)
    {
    GArray[i].WriteGradeData(cout);
    cout << endl;
    totalscore += GArray[i].GetScore();
    totalpossible += GArray[i].GetPossible();
    
    }	
     	i++;
	}
 cout << setw (20) << right << "---";
 cout << setw (10) << "---" << endl;
 cout << setw(20) << totalscore;
 cout << setw(10) << totalpossible << endl;
 percentage = (totalscore/totalpossible)*100;
 overallscore += totalscore;
 overalltotal += totalpossible;
 totalpercentage += percentage*.3;
 cout << "Projects Percentage: " << setprecision(3) << percentage << "%" << endl << endl;
 //_________________________________________________________________________________  
  cout << "Quizzes and Tests Report" << endl;
  cout << setw (5) << left << "Type";
  cout << setw (5) << "Date";
  cout << setw (10) << right << "Score";
  cout << setw (10) << right << "Possible";
  cout << setw (8) << right << "Grade";
  cout << setw (50) << left << "   Title" << endl;
 i = 0;
 char q = 'Q';
 char t = 'T';
 totalscore = 0;
 totalpossible = 0;
 percentage = 0;
 while (i < count)
	{
    if (GArray[i].GetGType() == q || GArray[i].GetGType() == t)
    {
      GArray[i].WriteGradeData(cout);
      cout << endl;
      totalscore += GArray[i].GetScore();
      totalpossible += GArray[i].GetPossible();
    }	
     	i++;
	}
 cout << setw (20) << right << "---";
 cout << setw (10) << "---" << endl;
 cout << setw(20) << totalscore;
 cout << setw(10) << totalpossible << endl;
 percentage = (totalscore/totalpossible)*100;
 overallscore += totalscore;
 overalltotal += totalpossible;
 overallgrade = (overallscore/overalltotal) * 100;
 totalpercentage += percentage*.5;
 cout << "Quizzes and Tests Percentage: " << setprecision(3) << percentage << "%" << endl << endl;
 
  char a = 'A';
	char b = 'B';
  if (totalpercentage >= 90)
   cout << "Overall Percentage: " << setprecision(3) << totalpercentage << "%" << "   Grade: " << a << endl;
  if (totalpercentage >= 80 && totalpercentage <=89)
   cout << "Overall Percentage: " << setprecision(3) << totalpercentage << "%  " << "   Grade: " << b << "+" << endl;

}
}

void Swap(Grade & a, Grade & b)
{
	Grade temp = a;
	a = b;
	b = temp;
}

void WordSort(Grade GArray[], int N)
{
  int i = 1;
  while (i < N)
    {
      int j = i;
      while (j > 0 && GArray[j] < GArray[j-1])
	{        
	  swap(GArray[j], GArray[j - 1]);
	  j--;
	}
      i++;
    }
}
