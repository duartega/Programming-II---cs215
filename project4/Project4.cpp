// Author : Gabriel Duarte
// File   : Project4.cpp
// Date   : 12/8/17
// Class  : Cs215
// Files  : OrderedSet.hpp & WordData.h


#include <iostream>
#include <fstream>
#include "OrderedSet.hpp"
#include "WordData.h"
using namespace std;

int WordDataTest (string file); // Prototype

int main (int argc, char * argv [])
{
  WordDataTest ("words.txt");
  return 0;
}

int WordDataTest (string file) // Function
{
  cout << "Testing OrderedSet with WordData:\n\n";

  ifstream input (file.c_str());

  WordData oneword;

  OrderedSet<WordData> WD;

  while (input >> oneword)
    WD.Insert (oneword);

  input.close();

  OrderedSet<WordData>::Iterator itr;

  cout << "From first to last:\n";

  for (itr = WD.begin(); itr != WD.end(); itr++)
    cout << '\t' << *itr << endl;

  cout << "From last to first:\n";

  for (itr = WD.rbegin(); itr != WD.rend(); --itr)
    cout << '\t' << *itr << endl;

  cout << "End of OrderedSet with WordData test\n\n";

  string computer = "computers";
  string a = "a";
  string submarine = "submarines";
  string word = "word";
  string thiss = "this";
  
  // WD.Delete(computer);
  //WD.Delete(a);
  // WD.Delete(submarine);
  //WD.Delete(word);
  //WD.Delete(thiss);


  string aod;
  string wordtodelete;
  string wordtoadd;
  cout << "\nIf you would like to delete a word, type delete.\nIf you would like to add a word, type add: ";
  cin >> aod;

  if (aod == "delete"){
    cout << "Enter word to delete (case sensitive): ";
    cin >> wordtodelete;
    WD.Delete(wordtodelete);

    for (itr = WD.begin(); itr != WD.end(); itr++)
      cout << '\t' << *itr << endl;
  
    while (wordtodelete != "quit")
      {
	cout << "\nEnter another word to delete or type 'quit' to stop: ";
	cin >> wordtodelete;
	WD.Delete(wordtodelete);
	cout << endl;
	for (itr = WD.begin(); itr != WD.end(); itr++)
	  cout << '\t' << *itr << endl;
      }
  }

  if (aod == "add"){
    cout << "Enter the word you would like to add: ";
    cin >> wordtoadd;
    WD.Insert(wordtoadd);

    for (itr = WD.begin(); itr != WD.end(); itr++)
      cout << '\t' << *itr << endl;

    while (wordtoadd != "quit"){
      	cout << "\nEnter another word to add or type 'quit' to stop: ";
	cin >> wordtoadd;
	WD.Insert(wordtoadd);
	cout << endl;
	for (itr = WD.begin(); itr != WD.end(); itr++)
	  cout << '\t' << *itr << endl;
      }

      
  }

  
  // string testword = "TestWord";
  
  //WD.Insert(testword);

  // cout << "After deleting the words 'computers', 'a', 'submarines', 'word', 'this' and adding 'TestWord'\n";
  
  //for (itr = WD.begin(); itr != WD.end(); itr++)
  // cout << '\t' << *itr << endl;
  
return 0;
}
