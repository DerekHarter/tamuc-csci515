/**
 * @author Derek Harter
 * @cwid   123 45 678
 * @class  CSci 515, Spring 2015
 * @ide    Emacs, GCC/G++
 * @date   February 5, 2015
 * @assg   Lecture 04, P01 Math Library Example
 *
 * @description Demonstration of standard math library functions.
 */
#include <iostream>
#include <cmath>
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
  // sqrt
  cout << "Square root of 4.0: " << sqrt(4.0) << endl;
  cout << "Square root of 2.0: " << sqrt(2.0) << endl;

  // Return 0 to indicate successful completion
  return 0;
}