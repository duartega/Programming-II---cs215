#ifndef OrderedSet_hpp
#define OrderedSet_hpp
#include <iostream>
#include <cstdlib>
#include <sstream>

using namespace std;

enum dtype {forward, backward};

template <class ST> class OrderedSet;
template <class ST> ostream & operator << (ostream & outs, const OrderedSet<ST> & L);

template <class ST>
class OrderedSet {
private:
  struct LinkedNode{
    LinkedNode ();
    ST data;
    LinkedNode * next;
    LinkedNode * prev;
  };
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
    Iterator (LinkedNode *  NP);
    ST & operator * () const;
    Iterator operator ++ ();
    Iterator operator ++ (int);
    Iterator operator -- ();
    Iterator operator -- (int);
    bool operator == (const Iterator & other) const;
    bool operator != (const Iterator & other) const;
  private:
    LinkedNode * current;
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
  LinkedNode * first;
  LinkedNode * last;
  int size;
  dtype direction;
  bool InsertFirst (const ST & value);
  bool InsertLast (const ST & value);
  bool DeleteFirst ();
  bool DeleteLast ();
  
};

//------EXCEPTION------------------------------------
template <class ST>
OrderedSet<ST>::Exception::Exception()
{
}
template <class ST>
OrderedSet<ST>::Exception::Exception (string msg)
{
  message = msg;
}
template <class ST>
OrderedSet<ST>::Exception::Exception(int idx)
{
  stringstream ss (stringstream::in | stringstream::out);
  ss << "Subscript [" << idx << "] out of range";
  getline (ss, message);
}
template <class ST>
string OrderedSet<ST>::Exception::Message() const
{
  return message;
}

//---------------------------------------------------
template <class ST>
void OrderedSet<ST>::Clear() {
  for (LinkedNode * temporaryNode = first; temporaryNode != NULL; temporaryNode = temporaryNode->next)
    DeleteFirst();
}

template <class ST>
bool OrderedSet<ST>::IsEmpty() const {
  if (size == 0)
    return true;
  return false;
}

template <class ST>
bool OrderedSet<ST>::IsIn (const ST & value) const {
  for (LinkedNode * temporaryNode = first; temporaryNode != NULL; temporaryNode = temporaryNode -> next)
    if (temporaryNode -> data == value)
      return true;
  return false;
}

template <class ST>
bool OrderedSet<ST>::Insert (const ST & value) {
  if (IsEmpty == true)
    return InsertFirst(value);

  if (value > last->data)
    return InsertLast(value);
  else
    return InsertFirst(value);

  if (IsIn(value) == true)
    return false;
  
  for (LinkedNode*tempnode = first; tempnode != NULL; tempnode = tempnode->next) {
    if (value < tempnode->data) {
      LinkedNode*t2 = new LinkedNode;
      t2->data = value;
      t2->next = tempnode;
      t2->prev = tempnode->prev;
      tempnode->prev = t2;
      tempnode->prev->prev->next = t2;
      size++;
      return true;
    }
  }
}
#endif
