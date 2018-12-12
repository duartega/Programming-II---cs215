#include <iostream>
#include "LList.hpp"
using namespace std;

int main()
{

  // Step 20
  LList<int> intList;
  LList<string> stringList;
  cout << "Integer list: " << intList << endl;
  cout << "string list: " << stringList << endl;

  // Step 21
  
  intList.InsertLast (-1);
    
  intList.InsertLast (-25);
    
  cout << endl;
  intList.InsertFirst (10);
  intList.InsertFirst (42);
  stringList.InsertFirst ("Hello");
  stringList.InsertLast ("World");
  stringList.InsertFirst ("Duh");
  stringList.InsertLast ("Man");
  cout << "Inserting -1 to the end";
  cout << endl;
  cout << "Inserting -25 to the end";  
  cout << endl;
  cout << "Inserting 10 to the front";
  cout << endl;
  cout << "Inserting 42 to the front";
  cout << endl;
  cout << "Integer list: " << intList;
  cout << endl;
  cout << "String list: " << stringList;
  cout << endl;

  // Step 22
  intList.SetDirection (BACKWARD);
  stringList.SetDirection (BACKWARD);
  cout << "Integer list: " << intList;
  cout << endl;
  cout << "String list: " << stringList;
  cout << endl;
  intList.SetDirection (FORWARD);
  stringList.SetDirection (FORWARD);
  cout << "Integer list: " << intList;
  cout << endl;
  cout << "String list: " << stringList;
  cout << endl;

  // Step 23
  
  intList.DeleteLast ();
  intList.DeleteFirst ();
  stringList.DeleteFirst ();
  stringList.DeleteLast ();
  cout << "Integer list: " << intList;
  cout << endl;
  cout << "String list: " << stringList;
  cout << endl;
  
  return 0;
}
