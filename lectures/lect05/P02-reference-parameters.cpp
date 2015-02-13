/**
 * @author Derek Harter
 * @cwid   123 45 678
 * @class  CSci 515, Spring 2015
 * @ide    Emacs, GCC/G++
 * @date   February 5, 2015
 * @assg   Lecture 04, P02 User Defined Functions
 *
 * @description Call by reference and call by value examples.
 */
#include <iostream>
using namespace std;


int myGlobalVariable; // a global variable, usually not a good idea to use these
const int MAX_VALUE = 1234; // global constants, however, are often useful


/** a function
 * A generic function.  Takes a single integer parameter as input, and returns
 * an integer as its result.
 *
 * @param x An integer input to our function.
 *
 * @returns An int value.  
 */
int aFunction(int x)
{
  myGlobalVariable = 42;
  x = 25;
  return 32;
}

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
