// Author      : Gabriel Duarte
// Date        : 11/8/2017
// Lab         : 08
// Description : This program will compute area and perimeter for each shape given.
// Notes       : This lab will be extra credit.


#include "Square.h"
using namespace std;

Square::Square()
{
  length = 0;
}

Square::Square(const Square & S)
{
}

Square::Square(float L)
{
}

Square::~Square()
{
}

Square & Square::operator = (const Square & S)
{
  return * this;
}

string Square::GetType () const
{
  return "Square";
}

void Square::SetLength (float L)
{
  // It is either this or L = length;
  length = L;
}

float Square::GetLength () const
{
  return length;
}

float Square::GetArea () const
{
  return (length*2);
}

float Square::GetPerimeter () const
{
  return (length*4);
}

bool Square::operator == (const Square & S) const
{
  return false;
}

bool Square::operator < (const Square & S) const
{
  return false;
}

ostream & operator << (ostream & outs, const Square & S)
{
  return outs;
}
