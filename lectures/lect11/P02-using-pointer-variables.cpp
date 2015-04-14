/**
 * @author Derek Harter
 * @cwid   123 45 678
 * @class  CSci 515, Spring 2015
 * @ide    Emacs, GCC/G++
 * @date   April 12, 2015
 * @assg   Lecture 11, P02 Using pointer variables
 *
 * @description Example of dereferencing pointer variables to read/write to
 *    memory they point from/to.
 */
#include <iostream>
#include <iomanip>
#include <cstdlib>
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
  // declare some pointers.
  double x = 5;
  double* xPtr = &x;

  // reading from variable
  cout << "Value of x is: " << x << endl;
  cout << "Value of x is: " << *xPtr << endl;

  // read value from dereference to use in an expression
  int y = 7;
  y = *xPtr + 5;
  cout << "Value of y is: " << y << endl;

  // writing new values to dereferenced memory
  *xPtr = 42;
  cout << "Value of x is now: " << x << endl;
  cout << "Value of x is now: " << *xPtr << endl;
  
  // return 0 to indicate successfull completion.
  return 0;
}
