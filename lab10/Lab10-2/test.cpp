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
  intList.InsertFirst (10);
  stringList.InsertFirst ("Hello");
  stringList.InsertLast ("World");
  cout << "Integer list: " << intList << endl;
  cout << "String list: " << stringList << endl;

  // Step 22
  intList.SetDirection (BACKWARD);
  stringList.SetDirection (BACKWARD);
  cout << "Integer list: " << intList << endl;
  cout << "String list: " << stringList << endl;
  intList.SetDirection (FORWARD);
  stringList.SetDirection (FORWARD);
  cout << "Integer list: " << intList << endl;
  cout << "String list: " << stringList << endl;

  // Step 23
  /*
  intList.DeleteLast (-1);
  intList.DeleteFirst (10);
  stringList.DeleteFirst ("Hello");
  stringList.DeleteLast ("World");
  cout << "Integer list: " << intList << endl;
  cout << "String list: " << stringList << endl;
  */
  return 0;
}
