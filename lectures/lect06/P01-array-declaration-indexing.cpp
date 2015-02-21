/**
 * @author Derek Harter
 * @cwid   123 45 678
 * @class  CSci 515, Spring 2015
 * @ide    Emacs, GCC/G++
 * @date   February 5, 2015
 * @assg   Lecture 06, P01 Array declarations and indexing
 *
 * @description Array creation, indexing.
 */
#include <iostream>
using namespace std;

/** main entry point
 * The main entry point for this program.  Execution
 * of this program will begin with this function.
 *
 * @returns An int value.  By default, if we don't specify a return or
 *           exit value, 0 is returned to indicate successful program
 *           completion.  A non-zero value indicates an error or
 *           problem with execution.
 */
int main()
{
  int x;
  int y;
  
  myGlobalVariable = 5;
  x = 10;
  y = aFunction(x);

  cout << "x = " << x << endl;
  cout << "y = " << y << endl;
  cout << "myGlobalVariable = " << myGlobalVariable << endl;

  if (x < y)
  {
    int y = -9999;
    cout << "y = " << y << endl;
  }
  
  cout << "y = " << y << endl;
}
