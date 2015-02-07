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
using namespace std;


/** A
 * The function A
 *
 * @param int p When p is less than 2 we call B().  In all cases we then print the value of p.
 */
void A(int p)
{

  if (a < 2)
  {
    B(p);
  }

  cout << a << endl;
}


/** B
 * The function B
 *
 * @param int p My parameter p is local to this functions invocation.
 */
void B(int p)
{
  p = 42;
  C();
}


/** B
 * The function B
 *
 * @param int p My parameter p is local to this functions invocation.
 */
void B(int p)
{
  p = 42;
  C();
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

  A(1);
}
