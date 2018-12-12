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
#include <sstream>
using namespace std;

enum dtype { FORWARD, BACKWARD };

template <class ST> class OrderedSet;
template <class ST> ostream & operator << (ostream & outs, const OrderedSet<ST> & L);

/*********************************************************************
 * Class: LList                                                       *
 *                                                                    *
 * Description: This class is designed to print nodes, go forward and *
 *              backward, and also insert and delete nodes.           *
 *********************************************************************/

template <class ST>
class OrderedSet
{
private:
  struct LNode
  {
    LNode ();
    ST data;
    LNode * next;
    LNode * prev;
  };
public:
  class Exception
  {
  public:
    Exception ();
    Exception (string msg);
    Exception (int idx);

    string Message() const;

  private:
    string message;
  };
    
  class Iterator {
  public:
    Iterator();
    Iterator (LNode *  NP);
    ST & operator * () const;
    Iterator operator ++ ();
    Iterator operator ++ (int);
    Iterator operator -- ();
    Iterator operator -- (int);
    bool operator == (const Iterator & other) const;
    bool operator != (const Iterator & other) const;
  private:
    LNode * current;
  };
    
  OrderedSet ();
  OrderedSet (const OrderedSet & other);
  ~OrderedSet ();
  OrderedSet & operator = (const OrderedSet & other);
  bool operator == (const OrderedSet & other);
  int Size () const;
  void SetDirection (dtype dir);
  dtype GetDirection () const;
  void Forward (void function  (const ST & param));
  void Backward (void function (const ST & param));
  friend ostream & operator << <> (ostream & outs, const OrderedSet<ST> & L);
  Iterator begin() const;
  Iterator rbegin() const;
  Iterator end() const;
  Iterator rend() const;
  ST & operator [] (const int & index) const;

  void Clear();
  bool IsEmpty () const;
  bool IsIn (const ST & value) const;
  bool Insert (const ST & value);
  bool Delete(const ST & value);
  OrderedSet operator + (const OrderedSet & other);
  OrderedSet operator * (const OrderedSet & other);
private:
  LNode * first;
  LNode * last;
  int size;
  dtype direction;
  bool InsertFirst (const ST & value);
  bool InsertLast (const ST & value);
  bool DeleteFirst ();
  bool DeleteLast ();

};

/*******************************************************************************
 * Function: Exception()                                                        *
 *                                                                              *
 * Parameters: None                                                             *
 * Return value: None                                                           *
 * Description: This function will just serve as the constructor.               *
 *******************************************************************************/

template <class ST>
OrderedSet<ST>::Exception::Exception()
{
}

/*******************************************************************************
 * Function: Exception(string msg                                               *
 *                                                                              *
 * Parameters: string msg                                                       *
 * Return value: None                                                           *
 * Description: This function will set the message to pass to exception()       *
 *******************************************************************************/

template <class ST>
OrderedSet<ST>::Exception::Exception (string msg)
{
  message = msg;
}

/*******************************************************************************
 * Function: Exception(int idx)                                                 *
 *                                                                              *
 * Parameters: int idx                                                          *
 * Return value: None                                                           *
 * Description: This function will only be called for indexes and print the msg *
 *******************************************************************************/

template <class ST>
OrderedSet<ST>::Exception::Exception(int idx)
{
  stringstream ss (stringstream::in | stringstream::out);
  ss << "Subscript [" << idx << "] out of range";
  getline (ss, message);
}

/*******************************************************************************
 * Function: Message()                                                          *
 *                                                                              *
 * Parameters: None                                                             *
 * Return value: Message                                                        *
 * Description: This function will return the message                           *
 *******************************************************************************/

template <class ST>
string OrderedSet<ST>::Exception::Message() const
{
  return message;
}

/*******************************************************************************
 * Function: Clear()                                                            *
 *                                                                              *
 * Parameters: None                                                             *
 * Return value: None                                                           *
 * Description: This function will clear the entire linked list.                *
 *******************************************************************************/

template <class ST>
void OrderedSet<ST>::Clear()
{
  for (LNode *temp = first; temp != NULL; temp = temp->next)
    DeleteFirst();
}

/*******************************************************************************
 * Function: IsEmpty()                                                          *
 *                                                                              *
 * Parameters: None                                                             *
 * Return value: True or false                                                  *
 * Description: This function will check to see if the list is empty.           *
 *******************************************************************************/

template <class ST>
bool OrderedSet<ST>::IsEmpty() const
{
  if (size == 0)
    return true;
  return false;
}
/*******************************************************************************
 * Function: IsIn(const ST & value)                                             *
 *                                                                              *
 * Parameters: const ST & value                                                 *
 * Return value: true or false                                                  *
 * Description: This function will check if the value is in the list.           *
 *******************************************************************************/

template <class ST>
bool OrderedSet<ST>::IsIn (const ST & value) const
{
  for (LNode *temp = first; temp != NULL; temp = temp->next)
    if (temp->data == value)
      return true;
  return false;
}

/*******************************************************************************
 * Function: Insert(const ST & value)                                           *
 *                                                                              *
 * Parameters: const ST & value                                                 *
 * Return value: None                                                           *
 * Description: This function will the list in sorted order.                    *
 *******************************************************************************/

template <class ST>
bool OrderedSet<ST>::Insert (const ST & value)
{
  if (IsEmpty() == true) // Checks to see if the lsit is empty
    return InsertFirst(value); // Returns inserting the first value

  if (value > last->data) // Checks to see if the value is greater than last so we dont have to iterate through the list
    return  InsertLast(value); // Returns inserting the value in the last position
  
  if (value < first->data) // Checks to see if the value is less than the first so we dont have to iterate through the list
    return InsertFirst(value); // Returns inserting the value in the first position
  
  for (LNode *temp = first; temp != NULL; temp = temp->next)
    {
      if (IsIn(value) == true) // Checks to see if the value is in the list
	return false;
      
      else {
		
	if (value < temp->data) // Inserts right before the next node which is bigger
	  {
	    LNode *temp2 = new LNode;
	    temp2->data = value;
	    temp2->next = temp;
	    temp2->prev = temp->prev;
	    temp->prev = temp2;
	    temp->prev->prev->next = temp2;
	    size++;
	    return true;
	  }
      }
    }
  return false;
}

/*******************************************************************************
 * Function: Delete(const ST & value)                                           *
 *                                                                              *
 * Parameters: const ST & value                                                 *
 * Return value: None                                                           *
 * Description: This function will delete the value requested.                  *
 *******************************************************************************/

template <class ST>
bool OrderedSet<ST>::Delete (const ST & value)
{
  if (IsIn(value) == false)
    return false;
  
  if (size == 1)
    return DeleteFirst();

  if (last->data == value)
    return DeleteLast();
      
  if (first->data == value)
    return DeleteFirst();
    
  for (LNode *temp = first; temp != NULL; temp = temp->next)
    {
      if (temp->data == value)
	{
	  temp->prev->next = temp->next;
	  temp->next->prev = temp->prev;
	  delete temp;
	  size--;
	  return true;
	}
    }
}

/*******************************************************************************
 * Function: operator + (const OrderedSet & other)                              *
 *                                                                              *
 * Parameters: const OrderedSet & other                                         *
 * Return value: result                                                         *
 * Description: This function will return the union set of both sets.           *
 *******************************************************************************/

template <class ST>
OrderedSet<ST> OrderedSet<ST>::operator + (const OrderedSet & other)
{
  OrderedSet <ST> result;
  for (LNode *temp = first; temp != NULL; temp = temp->next)
    result.Insert(temp->data);
  for (LNode *temp = other.first; temp != NULL; temp = temp->next)
    result.Insert(temp->data);
  return result;
}

/*******************************************************************************
 * Function: operator * (const ST & value)                                      *
 *                                                                              *
 * Parameters: const ST & value                                                 *
 * Return value: result                                                         *
 * Description: This function will return the intersection of both sets.        *
 *******************************************************************************/

template <class ST>
OrderedSet<ST> OrderedSet<ST>::operator * (const OrderedSet & other)
{
  OrderedSet<ST> result;
  for (LNode *temp = first; temp != NULL; temp = temp->next)
    if (other.IsIn(temp->data))
      result.Insert(temp->data);

  return result;
}

/*******************************************************************************
 * Function: LNode()                                                            *
 *                                                                              *
 * Parameters: None                                                             *
 * Return value: None                                                           *
 * Description: This function will initialize the values to 0 and NULL          *
 *******************************************************************************/
template <class ST>
OrderedSet<ST>::LNode::LNode ()
{
  next = NULL;
  prev = NULL;
}

/*******************************************************************************
 * Function: operator [] (const int & index) const                              *
 *                                                                              *
 * Parameters: const int & index                                                *
 * Return value: n->data                                                        *
 * Description: This function will return the value at a certain index.         *
 *******************************************************************************/

template <class ST>
ST & OrderedSet<ST>::operator [](const int & index) const
{
  if ( index < 0)
    throw (Exception(index));
  if (index >= size)
    throw (Exception(index));

  typename OrderedSet<ST>::LNode * n = first;
  for (int i = 0; i < index; i++)
    n = n->next;
  return n->data;
}

/*******************************************************************************
 * Function: operator * () const                                                *
 *                                                                              *
 * Parameters: None                                                             *
 * Return value: current->data                                                  *
 * Description: This function will return current->data but catch exceptions.   *
 *******************************************************************************/

template <class ST>
ST & OrderedSet<ST>::Iterator::operator * () const
{
  if (current == NULL)
    throw (Exception ("Cannot dereference a NULL pointer"));
  return current->data;
}

/*******************************************************************************
 * Function: Iterator()                                                         *
 *                                                                              *
 * Parameters: None                                                             *
 * Return value: None                                                           *
 * Description: This function will set the current to null.                     *
 *******************************************************************************/

template <class ST>
OrderedSet<ST>::Iterator::Iterator()
{
  current = NULL;
}

/*******************************************************************************
 * Function: Iterator(LNode * NP)                                               *
 *                                                                              *
 * Parameters: LNode * NP                                                       *
 * Return value: None                                                           *
 * Description: This function will set current to NP.                           *
 *******************************************************************************/

template <class ST>
OrderedSet<ST>::Iterator::Iterator (LNode * NP)
{
  current = NP;
}

/*************************************************************************************
 * Function: operator ++ ()                                                           *
 *                                                                                    *
 * Parameters: None                                                                   *
 * Return value: *this                                                                *
 * Description: This function will increment and throw exceptions when current == NULL*
 *************************************************************************************/

template <class ST>
typename OrderedSet<ST>::Iterator OrderedSet<ST>::Iterator::operator ++ ()
{
  if ( current == NULL )
    throw (Exception("Cannot increment a NULL iterator"));
  
  current = current->next;
  return *this;
}

/*******************************************************************************
 * Function: operator ++ (int)                                                  *
 *                                                                              *
 * Parameters: int                                                              *
 * Return value: temp                                                           *
 * Description: This function will post increment and throw exceptions.         *
 *******************************************************************************/

template <class ST>
typename OrderedSet<ST>::Iterator OrderedSet<ST>::Iterator::operator ++ (int)
{
  if ( current == NULL )
    throw (Exception("Cannot increment a NULL iterator"));
  
  Iterator temp = *this;
  current = current->next;
  return temp;
}

/*******************************************************************************
 * Function: operator -- ()                                                     *
 *                                                                              *
 * Parameters: None                                                             *
 * Return value: *this                                                          *
 * Description: This function will decrement and throw exceptions.              *
 *******************************************************************************/

template <class ST>
typename OrderedSet<ST>::Iterator OrderedSet<ST>::Iterator::operator -- ()
{
  if ( current == NULL )
    throw (Exception("Cannot decrement a NULL iterator"));

  current = current->prev;
  return *this;
}

/*******************************************************************************
 * Function: operator -- (int)                                                  *
 *                                                                              *
 * Parameters: int                                                              *
 * Return value: temp                                                           *
 * Description: This function will decrement and throw exceptions.              *
 *******************************************************************************/

template <class ST>
typename OrderedSet<ST>::Iterator OrderedSet<ST>::Iterator::operator -- (int)
{
  Iterator temp = *this;
  
  if ( current == NULL )
    throw (Exception("Cannot decrement a NULL iterator"));

  current = current->prev;
  return temp;
}

/*******************************************************************************
 * Function: operator == (const Iterator & other)                               *
 *                                                                              *
 * Parameters: const Iterator & other                                           *
 * Return value: current == other.current                                       *
 * Description: This function will the compared values.                         *
 *******************************************************************************/

template <class ST>
bool OrderedSet<ST>::Iterator::operator == (const Iterator & other) const
{
  return current == other.current;
}

/*******************************************************************************
 * Function: operator != (const Iterator & other)                               *
 *                                                                              *
 * Parameters: const Iterator & other                                           *
 * Return value: current != other.current                                       *
 * Description: This function will return saying the do not equal eachother.    *
 *******************************************************************************/

template <class ST>
bool OrderedSet<ST>::Iterator::operator != (const Iterator & other) const
{
  return current != other.current;
}

/*******************************************************************************
 * Function: begin()                                                            *
 *                                                                              *
 * Parameters: None                                                             *
 * Return value: temp                                                           *
 * Description: This function will return the first node in the list.           *
 *******************************************************************************/

template <class ST>
typename OrderedSet<ST>::Iterator OrderedSet<ST>::begin() const
{
  Iterator temp(first);
  return temp;
}
/*******************************************************************************
 * Function: rbegin()                                                           *
 *                                                                              *
 * Parameters: None                                                             *
 * Return value: temp                                                           *
 * Description: This function will return the last node in the list.            *
 *******************************************************************************/

template <class ST>
typename OrderedSet<ST>::Iterator OrderedSet<ST>::rbegin() const
{
  Iterator temp(last);
  return temp;
}

/*******************************************************************************
 * Function: end()                                                              *
 *                                                                              *
 * Parameters: None                                                             *
 * Return value: temp                                                           *
 * Description: This function will return the last element or node.             *
 *******************************************************************************/

template <class ST>
typename OrderedSet<ST>::Iterator OrderedSet<ST>::end() const
{
  Iterator temp;
  return temp;
}

/*******************************************************************************
 * Function: rend()                                                             *
 *                                                                              *
 * Parameters: None                                                             *
 * Return value: temp                                                           *
 * Description: This function will return the first element or node in the list.*
 *******************************************************************************/

template <class ST>
typename OrderedSet<ST>::Iterator OrderedSet<ST>::rend() const
{
  Iterator temp;
  return temp;
}
/*******************************************************************************
 * Function: OrderedSet()                                                       *
 *                                                                              *
 * Parameters: None                                                             *
 * Return value: None                                                           *
 * Description: This function will initialize the values to 0 and NULL          *
 *******************************************************************************/

template <class ST>
OrderedSet<ST>::OrderedSet ()
{
  size = 0;
  first = NULL;
  direction = FORWARD;
  last = NULL;
}

/*******************************************************************************
 * Function: Forward (void function (const ST & param))                         *
 *                                                                              *
 * Parameters: None                                                             *
 * Return value: None                                                           *
 * Description: This function will allow us to traverse forward in the list.    *
 *******************************************************************************/

template <class ST>
void OrderedSet<ST>::Forward (void function (const ST & param))
{
  for (LNode * n = first; n;  n = n->next)
    function (n->data);
}

/*******************************************************************************
 * Function: Backward (coid function (const ST & param))                        *
 *                                                                              *
 * Parameters: None                                                             *
 * Return value: None                                                           *
 * Description: This function will allow us to traverse backward in the list.   *
 *******************************************************************************/

template <class ST>
void OrderedSet<ST>::Backward (void function (const ST & param))
{
  for (LNode * n = last; n;  n = n->prev)
    function (n->data);
}

/*********************************************************************
 * Function: OrderedSet (const OrderedSet & other)                    *
 *                                                                    *
 * Parameters: (const OrderedSet & other)                             *
 * Return value: None                                                 *
 * Description: This function will copy the values into other from    *
 *              the original list.                                    *
 *********************************************************************/

template <class ST>
OrderedSet<ST>::OrderedSet (const OrderedSet & other)
{
  size  = 0;
  first = last = NULL;
  for (LNode *temp = other.first; temp != NULL; temp = temp->next)
    InsertLast(temp->data);
  direction = other.direction;
}

/*********************************************************************
 * Function: ~OrderedSet()                                            *
 *                                                                    *
 * Parameters: None                                                   *
 * Return value: None                                                 *
 * Description: This function will delete the linked list.            *
 *********************************************************************/
template <class ST>
OrderedSet<ST>::~OrderedSet ()
{
  while (first != NULL)
    DeleteFirst();
}

/*********************************************************************
 * Function: operator = (const OrderedSet & other)                    *
 *                                                                    *
 * Parameters: (const OrderedSet & other)                             *
 * Return value: * this                                               *
 * Description: This function will set the assignment operator to call*
 *              the copy constructor to copt the linked list.         *
 *********************************************************************/

template <class ST>
OrderedSet<ST> & OrderedSet<ST>::operator = (const OrderedSet<ST> & other)
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
 * Function: operator == (const OrderedSet & other)                   *
 *                                                                    *
 * Parameters: (const OrderedSet & other)                             *
 * Return value: false, otherwise true                                *
 * Description: This function will compare each of the nodes.         *
 *********************************************************************/

template <class ST>
bool OrderedSet<ST>::operator == (const OrderedSet & other)
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

template <class ST>
int OrderedSet<ST>::Size () const
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

template <class ST>
void OrderedSet<ST>::SetDirection (dtype dir)
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

template <class ST>
dtype OrderedSet<ST>::GetDirection () const
{
  return direction;
}

/*********************************************************************
 * Function: operator << (ostream & outs, const OrderedSet & L)       *
 *                                                                    *
 * Parameters: (ostream & outs, const OrderedSet & L)                 *
 * Return value: outs                                                 *
 * Description: This function will write out the data in the list.    *
 *********************************************************************/

template <class ST>
ostream & operator << (ostream & outs, const OrderedSet<ST> & L)
{
  outs << "{";
  if (L.first == NULL)
    {
      outs << "}";
      return outs;
    }
  if (L.direction == FORWARD)
    { //Print the list from the beginning (first) to end
      outs << L.first->data;
      typename OrderedSet<ST>::LNode * temp;
      for (temp = L.first->next; temp != NULL; temp = temp->next)
	{
	  outs << ',' << temp->data;
	}
    }
  else // L.direciton == BACKWARD
    { // Print the list from end to beginning
      //L.first->PrintNode(outs, 2);
      //outs << L.last->data;
      typename OrderedSet<ST>::LNode * temp2;
      outs << L.last->data;
      for (temp2 = L.last->prev; temp2 != NULL; temp2 = temp2->prev)
	{
	  outs << ',' << temp2->data;
	}
    }
  outs << "}";
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

template <class ST>
bool OrderedSet<ST>::InsertFirst (const ST & value)
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

template <class ST>
bool OrderedSet<ST>::InsertLast (const ST & value)
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
 * Return value: true or false                                        *
 * Description: This function will delete the first node.             *
 *********************************************************************/

template <class ST>
bool OrderedSet<ST>::DeleteFirst ()
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
  

  return true;
}

/*********************************************************************
 * Function: DeleteLast()                                             *
 *                                                                    *
 * Parameters: None                                                   *
 * Return value: true or false                                        *
 * Description: This function will delete the last node.              *
 *********************************************************************/

template <class ST>
bool OrderedSet<ST>::DeleteLast ()
{
  if (size == 0 || first == NULL)
    return false;
  
  if (size == 1)
    return DeleteFirst();

  LNode * temp2 = last;

  last = temp2->prev;
  last->next = NULL;
  delete temp2;

  size--;
  
  return true;
}

/*******************************************************************************
 * Function: PrintValue (const int & value)                                     *
 *                                                                              *
 * Parameters: None                                                             *
 * Return value: None                                                           *
 * Description: This function will print out the value in the list.             *
 *******************************************************************************/

OrderedSet<int> L;
void PrintValue (const int & value)
{
  cout << "The value in the list is " << value << endl;
}

#endif
