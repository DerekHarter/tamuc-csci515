/**
 * @author Derek Harter
 * @cwid   123 45 678
 * @class  CSci 515, Spring 2015
 * @ide    Emacs, GCC/G++
 * @date   April 12, 2015
 * @assg   Lecture 11, P06 Multiple dereferencing and indirection
 *
 * @description An example of chaining memory derefernce multiple times.
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
  int x;
  int* xPtr = &x;
  int** xPtrPtr = &xPtr;

  **xPtrPtr = 42;
  cout << x << endl;

  // return 0 to indicate successfull completion.
  return 0;
}
