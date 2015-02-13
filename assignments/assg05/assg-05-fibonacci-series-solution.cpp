/**
 * @author Derek Harter
 * @cwid   123 45 678
 * @class  CSci 515, Spring 2015
 * @ide    Gnu C/C++, Emacs
 * @date   February 5, 2015
 * @assg   Assg 05
 *
 * @description Calculate the n^th term of the Fibonacci series.  We implement
 *    the algorithm to calculate this term using both an iterative approach and
 *    a recursive approach.
 */
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;


/** nth term of Fibonacci series (iterative)
 * Calculate the n^th term of the Fibonacci series.  Implement the
 * calculation using an iterative approach (use a loop).  We take a single
 * integer n as input, which is the term we are to calculate, and return the
 * nth term of the series as an integer for our result.
 *
 * @param n An integer value, the term of the series we are to
 * caclualte and return.
 *
 * @returns int The nth Fibonacci term
 */
int nthFibonacciIterative(int n)
{
  int nMinus1 = 0;
  int nMinus2 = 1;
  int nthTerm;
  
  // The base cases x_0 and x_1
  if (n == 0)
  {
    return 0;
  }
  if (n == 1)
  {
    return 1;
  }

  for (int i=2; i <= n; i++)
  {
    nthTerm = nMinus1 + nMinus2;
  }

  return nthTerm;
}


/** main entry point
 * The main entry point for this program.  Execution
 * of this program will beigin with this function.
 *
 * @returns An int value.  By default, if we don't specify a return or
 *           exit value, 0 is returned to indicate successful program
 *           completion.  A non-zero value indicates an error or
 *           problem with execution.  Summary information is calculated
 *           while processing the individual lines of input.
 */
int main()
{

  // clean up and return 0 to indicate successful completion
  return 0;
}
