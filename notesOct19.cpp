#include <iostream>

using namespace std;

int main()
{
  int ttt[3][3];
  ttt[1][1] = 1;

  // int x[5][2][3] Is the static array
  int ** thing = new int*[3]; // The int*[3] is a pointer to pointer 
  // This is the dymanic array
  // a -> [0, 1, 2]
  //       *  *  *
  //       |  \  \
  //       v   \  \
  //     [0,1,2] \ \________
  //              v        v
  //              [0,1,2] [0,1,2]
  for (int i = 0; i < 3; i++)
    thing[i] = new int[3];
  return 0;
}
