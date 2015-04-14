/**
 * @author Derek Harter
 * @cwid   123 45 678
 * @class  CSci 515, Spring 2015
 * @ide    Emacs, GCC/G++
 * @date   April 12, 2015
 * @assg   Lecture 11, P01 Pointer Variables and Operators Examples
 *
 * @description Example of declaring pointers, referencing and
 *    dereferencing them.
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
  int count;
  int* countPtr;
  double x;
  double* xPtr;

  // address of operators, initialize pointers
  countPtr = &count;
  xPtr = &x;

  // can initialize when declaring, as with regular variables
  double* anotherXPtr = &x;

  // return 0 to indicate successfull completion.
  return 0;
}
