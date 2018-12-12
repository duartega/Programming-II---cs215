#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "card.h"
#include "DuarteL11.hpp"

using namespace std;

int main()
{
  ifstream cards ("cards.in"); // This is saying to load this file for us to read
  card line;                   // This will help us read each line in the file
  LList2 <card> LS;            // Create a Linked List for the total cards
  LList2 <card> firstHalf;     // Create a first half linked list
  LList2 <card> secondHalf;    // Create a second half linked list
  LList2 <card> shuffledCards; // Create a shuffled card linked list
  
  int count = 0;               // Create a counter variable for size
  card d;                      // Create a read in variable
  int y = 0;                   // Create a counter variable also for size
      
  while (cards >> d)           // Read in the cards one by one
    {
      LS.InsertLast(d);        // Insert each card into the list
      count++;                 // Increment the size of the list
    }

  cout << "LS in order: ";     // Print out the list
  cout << LS << endl;          // Print out the list
  
  for (LList2<card>::Iterator i = LS.begin(); y < count/2; i++)
    {
      firstHalf.InsertLast(*i);// Insert the item into the firstHalf list
      y++;                     // Increment the count
    }
  cout << "This is first half: ";
  cout << firstHalf << endl;   // Print out the first half
  y = count;                   // Now y = count
  
  for (LList2<card>::Iterator i = LS.rbegin(); y > count/2; i--)
    {
      secondHalf.InsertFirst(*i);// Insert the item into the secondHalf list
      y--;                     // Decrement the count
    }

  cout << "This is second half: ";
  cout << secondHalf << endl;  // Print the secondHalf list

  
  LList2<card>::Iterator j = firstHalf.begin(); // Iterator for the first half
  LList2<card>::Iterator k = secondHalf.begin();// Iterator for the second half
  for (int i = 0; i < count; i++)
    {
      if (i % 2 == 1)          // Checks to see if the remainder is 1 or 0
	{
	  shuffledCards.InsertLast((*j)); // Inserts the card into the shuffled deck if it is a 1
	  j++;                 // Increment the j counter
	}
      else
	{
	  shuffledCards.InsertLast((*k)); // Iserts the card into the shuffled deck if it is a 0
	  k++;                 // Increment the k counter
	}
    }

  cout << "This is the shuffled deck: ";
  cout << shuffledCards << endl;  // Print out the shuffled deck
  
  return 0;
}
