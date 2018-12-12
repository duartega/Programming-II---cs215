#include <iostream>
#include <cstdlib>
#include "LList2.hpp"

using namespace std;

void Insert (OrderedSet <int> & S);
void TestDereference (OrderedSet <int>::Iterator itr);
void TestSubscript (OrderedSet <int> & S, int sub);


int main()
{
  srand (0);
  OrderedSet <int> S1;
  OrderedSet <int> S2;
  OrderedSet <int> Sum;
  OrderedSet <int> Intersection;
  //Insert(S1);
  //Insert(S2);
  
  
  S1.Insert(4);
  S1.Insert(-5);
  S1.Insert(-10);
  S1.Insert(3);
  S1.Insert(-1);
  S1.Insert(-4);
  S1.Insert(4);
  S1.Insert(-1);
  S1.Insert(-4);
  S1.Insert(-5);

  S2.Insert(9);
  S2.Insert(2);
  S2.Insert(-3);
  S2.Insert(5);
  S2.Insert(-9);
  S2.Insert(-9);
  S2.Insert(10);
  S2.Insert(-9);
  S2.Insert(1);
  S2.Insert(-1);


  
 cout << "Elements in S1: " << S1 << endl;
 cout << "Elements in S2: " << S2 << endl;

 TestDereference (S1.begin());
 TestDereference (S1.end());

 TestSubscript (S1, 1);
 TestSubscript (S1, -1);
 TestSubscript (S1, 1+S1.Size());

  Sum = S1 + S2;
  cout << "Union set: " << Sum << endl;

   Intersection = S1 *S2;
   cout << "Intersection: " << Intersection << endl;

   cout << "Elements in S2: " << S2.Size() << endl;
   S2.Delete(2);
   cout << "After deleting -1: " << S2 << endl;
   S2.Delete(-9);
   cout << "After deleting -9: " << S2 << endl;
   S2.Delete(-3);
   cout << "After deleting -3: " << S2 << endl;
   S2.Delete(10);
   cout << "After deleting 10: " << S2 << endl;
   S2.Delete(9);
   cout << "After deleting 9: " << S2 << endl;
   //S1.Clear();
     cout << "After Clearing: " << S1 << endl;
    
     for (int i = S1.Size()-1; i >= 0; --i)
       cout << "List value reversed is: " << S1[i] << endl;
     
     
  return 0;
}

void Insert (OrderedSet <int> & S)
{
  cout << "Insert  values in set:\n";
  for (int i = 0; i < 10; i++)
    { 
      S.Insert (-10 + rand() % 21);
    }
  cout << "Elements in S: " << S << endl;
}

void TestDereference (OrderedSet <int>::Iterator itr)
{
  try
    {
      cout << "Testing * operator:\n";
      int value = *itr;
      cout << "THe value at the iterator is: ";
      cout << value << endl;
    }
  catch (OrderedSet<int>::Exception E)
    {
      cerr << "Exception: " << E.Message() << endl;
      return;
    }
}

void TestSubscript (OrderedSet <int> & S, int sub)
{
  try
    {
      cout << "Testing [] operator:\n";
      int value = S[sub];
      cout << "The value at S[" << sub << "] is: ";
      cout << value << endl;
    }
  catch (OrderedSet <int>::Exception E)
    {
      cerr << "Exception: " << E.Message() << endl;
      return;
    }
}
