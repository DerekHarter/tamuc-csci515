/**
 * @author Derek Harter
 * @cwid   123 45 678
 * @class  CSci 515, Spring 2015
 * @ide    Emacs, GCC/G++
 * @date   February 5, 2015
 * @assg   Lecture 04, P02 User Defined Functions
 *
 * @description Lets define some of our own functions.
 */
#include <iostream>
#include <iomanip>
using namespace std;



/** Raise an integer power
 * Raise a given integer to the given (integer) power.
 *
 * @param int x The base we are raising to some power
 * @param int n The power to raise the base too.
 *
 * @returns int The base raised to the power, e.g. x^n
 */
int pow(int x, int n)
{
  // to raise x to the n power, we need to multiple x by itself n times
  int result = x;
  for (int i=2; i<=n; i++)
  {
    result *= x;
  }
  return result;
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
  // Return 0 to indicate successful completion
  cout << "3 ^ 2 : " << pow(3, 2) << endl;
  cout << "2 ^ 3 : " << pow(2, 3) << endl;
  cout << "3 ^ 3 : " << pow(3, 3) << endl;

  return 0;
}
