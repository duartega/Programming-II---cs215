/*********************************************************************
* Assignment: Lab 11 - Doubly Linked List implementation             *
* Author: Gabriel Duarte                                             *
* Date: Fall 2017                                                    *
* File: LList2.hpp                                                   *
*                                                                    *
* Description: This file contains the cpp and h file                 *
*********************************************************************/

#ifndef LLIST_HPP
#define LLIST_HPP
#include <iostream>
#include <cstdlib>
using namespace std;

enum dtype { FORWARD, BACKWARD };

template <class LT> class LList2;
template <class LT> ostream & operator << (ostream & outs, const LList2<LT> & L);

/*********************************************************************
* Class: LList                                                       *
*                                                                    *
* Description: This class is designed to print nodes, go forward and *
*              backward, and also insert and delete nodes.           *
*********************************************************************/

template <class LT>
class LList2
{
private:
  struct LNode
  {
    LNode ();
    LT data;
    LNode * next;
    LNode * prev;
  };
public:
  class Iterator {
  public:
    Iterator();
    Iterator (LNode *  NP);
    LT & operator * () const;
    Iterator operator ++ ();
    Iterator operator ++ (int);
    Iterator operator -- ();
    Iterator operator -- (int);
    bool operator == (const Iterator & other) const;
    bool operator != (const Iterator & other) const;
  private:
    LNode * current;
  };
    
  LList2 ();
  LList2 (const LList2 & other);
  ~LList2 ();
  LList2 & operator = (const LList2 & other);
  bool operator == (const LList2 & other);
  int Size () const;
  void SetDirection (dtype dir);
  dtype GetDirection () const;
  void Forward (void function  (const LT & param));
  void Backward (void function (const LT & param));
  friend ostream & operator << <> (ostream & outs, const LList2<LT> & L);
  bool InsertFirst (const LT & value);
  bool InsertLast (const LT & value);
  bool DeleteFirst ();
  bool DeleteLast ();
  Iterator begin() const;
  Iterator rbegin() const;
  Iterator end() const;
  Iterator rend() const;
  LT & operator [] (const int & index) const;
  
private:
  LNode * first;
  LNode * last;
  int size;
  dtype direction;
};

//#include "LList.h"

/*******************************************************************************
* Function: LNode()                                                            *
*                                                                              *
* Parameters: None                                                             *
* Return value: None                                                           *
* Description: This function will initialize the values to 0 and NULL          *
*******************************************************************************/
template <class LT>
LList2<LT>::LNode::LNode ()
{
  next = NULL;
  prev = NULL;
}

/*******************************************************************************
* Function: operator [](const int & index) const                               *
*                                                                              *
* Parameters: const int & index                                                *
* Return value: n->data                                                        *
* Description: This function will return the value at a certain index.         *
*******************************************************************************/
template <class LT>
LT & LList2<LT>::operator [](const int & index) const
{
  LList2<LT>::LNode * n = first;
  int count = 0;
  
   try
    {
      if ( index < 0 || index >= size  )
	throw ("Cannot dereference a NULL pointer");
      else
	{
	 for (LNode * n = first; n != NULL;  n = n->next)
	   {
	   if (count == index)
	     return  n->data;
	   count ++;

	 }
	}
    }
  catch (const char * message)
    {
      cerr << message << endl;
      exit (4);
    }
}

template <class LT>
LT & LList2<LT>::Iterator::operator * () const
{
  try
    {
      if (current == NULL)
	throw ("Cannot dereference a NULL pointer");
      return current->data;
    }
  catch (const char * message)
    {
      cerr << message << endl;
      exit(1);
    }
}

template <class LT>
LList2<LT>::Iterator::Iterator()
{
  current = NULL;
}

template <class LT>
LList2<LT>::Iterator::Iterator (LNode * NP)
{
  current = NP;
}


template <class LT>
typename LList2<LT>::Iterator LList2<LT>::Iterator::operator ++ ()
{
  try
    {
      if ( current == NULL )
	throw ("Cannot dereference a NULL pointer");
      return *this;
    }
  catch (const char * message)
    {
      cerr << message << endl;
      exit (2);
    }

  current = current->next;
  return *this;
}

template <class LT>
typename LList2<LT>::Iterator LList2<LT>::Iterator::operator ++ (int)
{
  Iterator temp = *this;
   try
    {
      if ( current->next == NULL )
	throw ("Cannot dereference a NULL pointer");
      return temp;
    }
  catch (const char * message)
    {
      cerr << message << endl;
      exit (2);
    }
  current = current->next;
  return temp;
}

template <class LT>
typename LList2<LT>::Iterator LList2<LT>::Iterator::operator -- ()
{
  try
    {
      if ( current == NULL )
	throw ("Cannot dereference a NULL pointer");
      return *this;
    }
  catch (const char * message)
    {
      cerr << message << endl;
      exit (3);
    }
  current = current->prev;
  return *this;
}

template <class LT>
typename LList2<LT>::Iterator LList2<LT>::Iterator::operator -- (int)
{
  Iterator temp = *this;
   try
    {
      if ( current->prev == NULL )
	throw ("Cannot dereference a NULL pointer");
      return temp;
    }
  catch (const char * message)
    {
      cerr << message << endl;
      exit (2);
    }
  current = current->prev;
  return temp;
}

template <class LT>
bool LList2<LT>::Iterator::operator == (const Iterator & other) const
{
  return current == other.current;
}

template <class LT>
bool LList2<LT>::Iterator::operator != (const Iterator & other) const
{
  return current != other.current;
}

template <class LT>
typename LList2<LT>::Iterator LList2<LT>::begin() const
{
  Iterator temp(first);
  return temp;
}

template <class LT>
typename LList2<LT>::Iterator LList2<LT>::rbegin() const
{
  Iterator temp(last);
  return temp;
}

template <class LT>
typename LList2<LT>::Iterator LList2<LT>::end() const
{
  Iterator temp(last);
  return temp;
}

template <class LT>
typename LList2<LT>::Iterator LList2<LT>::rend() const
{
  Iterator temp(first);
  return temp;
}
/*******************************************************************************
* Function: LList2()                                                            *
*                                                                              *
* Parameters: None                                                             *
* Return value: None                                                           *
* Description: This function will initialize the values to 0 and NULL          *
*******************************************************************************/

template <class LT>
LList2<LT>::LList2 ()
{
  size = 0;
  first = NULL;
  direction = FORWARD;
  last = NULL;
}

template <class LT>
void LList2<LT>::Forward (void function (const LT & param))
{
  for (LNode * n = first; n;  n = n->next)
    function (n->data);
}

template <class LT>
void LList2<LT>::Backward (void function (const LT & param))
{
  for (LNode * n = last; n;  n = n->prev)
    function (n->data);
}

/*********************************************************************
* Function: LList2 (const LList2 & other)                              *
*                                                                    *
* Parameters: (const LList2 & other)                                  *
* Return value: None                                                 *
* Description: This function will copy the values into other from    *
*              the original list.                                    *
*********************************************************************/

template <class LT>
LList2<LT>::LList2 (const LList2 & other)
{
  size  = 0;
  first = last = NULL;
  for (LNode *temp = other.first; temp != NULL; temp = temp->next)
      InsertLast(temp->data);
  direction = other.direction;
}

/*********************************************************************
* Function: ~LList2()                                                 *
*                                                                    *
* Parameters: None                                                   *
* Return value: None                                                 *
* Description: This function will delete the linked list.            *
*********************************************************************/
template <class LT>
LList2<LT>::~LList2 ()
{
  while (first != NULL)
    DeleteFirst();
}

/*********************************************************************
* Function: operator = (const LList2 & other)                         *
*                                                                    *
* Parameters: (const LList2 & other)                                  *
* Return value: * this                                               *
* Description: This function will set the assignment operator to call*
*              the copy constructor to copt the linked list.         *
*********************************************************************/

template <class LT>
LList2<LT> & LList2<LT>::operator = (const LList2<LT> & other)
{
  if (this == &other) // Step A
    return * this;
 
  while (first != NULL) // Step B
    DeleteFirst();
  for (LNode * temp = other.first; temp != NULL; temp = temp->next)
      InsertLast(temp->data);
  direction = other.direction;
 return * this;
}

/*********************************************************************
* Function: operator == (const LList2 & other)                        *
*                                                                    *
* Parameters: (const LList2 & other)                                  *
* Return value: false, otherwise true                                *
* Description: This function will compare each of the nodes.         *
*********************************************************************/

template <class LT>
bool LList2<LT>::operator == (const LList2 & other)
{
  if (size != other.size)
    return false;

  LNode * temp = first;
  LNode * tempOther = other.first;
  while (temp != NULL)
    {
      if (temp->data != tempOther->data)
	return false;
      temp = temp->next;
      tempOther = tempOther->next;
    }
  return true;
}

/*********************************************************************
* Function: Size() const                                             *
*                                                                    *
* Parameters: None                                                   *
* Return value: None                                                 *
* Description: This function will return the size                    *
*********************************************************************/

template <class LT>
int LList2<LT>::Size () const
{ 
	return size;
}

/*********************************************************************
* Function: SetDirection (dtype dir)                                 *
*                                                                    *
* Parameters: (dtype dir)                                            *
* Return value: None                                                 *
* Description: This function will set direction to dir.              *
*********************************************************************/

template <class LT>
void LList2<LT>::SetDirection (dtype dir)
{
  direction = dir;
}

/*********************************************************************
* Function: GetDirection (dtype dir)                                 *
*                                                                    *
* ParametersNone                                                     *
* Return value: Direction                                            *
* Description: This function will return direction.                  *
*********************************************************************/

template <class LT>
dtype LList2<LT>::GetDirection () const
{
  return direction;
}

/*********************************************************************
* Function: operator << (ostream & outs, const LList2 & L)            *
*                                                                    *
* Parameters: (ostream & outs, const LList2 & L)                      *
* Return value: outs                                                 *
* Description: This function will write out the data in the list.    *
*********************************************************************/

template <class LT>
ostream & operator << (ostream & outs, const LList2<LT> & L)
{
  if (L.first == NULL)
    return outs;
  if (L.direction == FORWARD)
  { //Print the list from the beginning (first) to end
    outs << L.first->data;
    typename LList2<LT>::LNode * temp;
    for (temp = L.first->next; temp != NULL; temp = temp->next)
      {
	outs << ' ' << temp->data;
      }
  }
  else // L.direciton == BACKWARD
  { // Print the list from end to beginning
    //L.first->PrintNode(outs, 2);
     
 typename LList2<LT>::LNode * temp2;
 
 for (temp2 = L.last; temp2 != NULL; temp2 = temp2->prev)
   {
     // It is only printing three and not two or one.
     // But if i say temp2->prev->data then it will
     // only print two, not three or one.
     outs << ' ' << temp2->data;
   }
  }
  return outs;
}


/*********************************************************************
* Function: InsertFirst (const int & value)                          *
*                                                                    *
* Parameters: (const int & value)                                    *
* Return value: true                                                 *
* Description: This function will insert a new node into the first   *
*              node.                                                 *
*********************************************************************/

template <class LT>
bool LList2<LT>::InsertFirst (const LT & value)
{
  LNode * newLNode = new LNode; 
  if (newLNode == NULL)
    return false;

  newLNode->data = value;
  newLNode->next = first;

  // This makes sure there is a node first other wise it cant make a previous
  if (size != 0) 
    first->prev = newLNode;
  
  first = newLNode; // Sets current node as first
  if (size == 0)
    last = newLNode;
  size++;
  return true;
}

/*********************************************************************
* Function: InsertLast (const int & value)                           *
*                                                                    *
* Parameters: (const int & value)                                    *
* Return value: true                                                 *
* Description: This function will insert a new node into the last    *
*              node.                                                 *
*********************************************************************/

template <class LT>
bool LList2<LT>::InsertLast (const LT & value)
{
  if (size == 0)
      return InsertFirst(value);

  LNode * newLNode = new LNode;
  if (newLNode == NULL)
    return false;
  
  newLNode->data = value;
  last->next = newLNode;
  newLNode->prev = last;
 
  last = newLNode;   

  size++;
  return true;
}

/*********************************************************************
* Function: DeleteFirst()                                            *
*                                                                    *
* Parameters: None                                                   *
* Return value: None                                                 *
* Description: This function will delete the first node.             *
*********************************************************************/

template <class LT>
bool LList2<LT>::DeleteFirst ()
{
  if (size == 0 || first == NULL)
    return false;

  LNode * temp = first;
 
  if (size == 1)
    {
      delete first;
      last = first = NULL;
      size--;
      return true;
    }
  else
    {
      first = temp->next;
      first->prev = NULL;
      delete temp;
      size--;
    }
  
  if (size == 0)
    last = NULL;

  return true;
}

/*********************************************************************
* Function: DeleteLast()                                             *
*                                                                    *
* Parameters: None                                                   *
* Return value: true                                                 *
* Description: This function will delete the last node.              *
*********************************************************************/

template <class LT>
bool LList2<LT>::DeleteLast ()
{
  if (size == 0 || first == NULL)
    return false;
  
  if (size == 1)
    return DeleteFirst();
  
  LNode * temp2 = first;
  
  while (temp2->next != last)
    temp2 = temp2->next;

  temp2->next = NULL;
  temp2->prev = last;
  delete last;
  
  last = temp2;
  LNode * temp3 = first;

  while (temp3->next != last)
    temp3 = temp3->next;  
  last->prev = temp3;
  size--;
  
  return true;
}

LList2<int> L;
void PrintValue (const int & value)
{
  cout << "The value in the list is " << value << endl;
}

#endif
