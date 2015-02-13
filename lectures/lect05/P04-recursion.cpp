/**
 * @author Derek Harter
 * @cwid   123 45 678
 * @class  CSci 515, Spring 2015
 * @ide    Emacs, GCC/G++
 * @date   February 5, 2015
 * @assg   Lecture 04, P02 User Defined Functions
 *
 * @description Example of iterative and recursive function implementations of effective procedures.
 */
#include <iostream>
#include <iomanip>
using namespace std;


/** factorial (iterative)
 * Calculate the factorial of an integer number n, e.g. n!
 *
 * @param n An integer number to find factorial of.
 *
 * @returns int The factorial of n, n!
 */
int factorialIterative(int n)
{
  int res = 1;

  for (int i = 1; i <= n; i++)
  {
    res = res * i;
  }

  return res;
}


/** factorial (recursive)
 * Calculate the factorial of an integer number n, e.g. n!
 *
 * @param n An integer number to find factorial of.
 *
 * @returns int The factorial of n, n!
 */
int factorialRecursive(int n)
{
  if (n == 0)
  {
    return 1;
  }
  else
  {
    return n * factorialRecursive(n-1);
  }
}


/** n^th Fibonacci number (iterative)
 * Calculate the nth term of the Fibonacci series using an iterative method.  The
 * Fibonacci sequence is defined as:
 *     0, 1, 1, 2, 3, 5, 8, 13, 21, ...
 *     where x_n = x_{n-1} + x_{n-2}
 *
 * @param n An integer, the term n we are to calculate.
 *
 * @returns int The n^th Fibonacci number in the sequence
 */
int nthFibonacciIterative(int n)
{
  if (n == 0)
  {
    return 0;
  }
  if (n == 1)
  {
    return 1;
  }

  int nth;
  int nMinusOne = 0;
  int nMinusTwo = 1;
  for (int i = 2; i <= n; i++)
  {
    // calculate the ith term (2,3,...)
    nth = nMinusOne + nMinusTwo;

    // save two previous terms for next iteration
    nMinusTwo = nMinusOne;
    nMinusOne = nth;
  }

  return nth;
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
  // Test factorial functions
  cout << "Factorial" << endl;
  cout << "---------" << endl;
  cout << setw(2) << right << "n"
       << setw(10) << right << "iterative"
       << setw(10) << right << "recursive" << endl;
  for (int i=0; i <= 10; i++)
  {
    cout << setw(2) << right << i
	 << setw(10) << right << factorialIterative(i)
	 << setw(10) << right << factorialRecursive(i) << endl;
  }

  // Test Fibonacci sequence
  cout << setw(2) << right << "n"
       << setw(10) << right << "iterative"
       << setw(10) << right << "recursive" << endl;
  for (int i=0; i <= 10; i++)
  {
    cout << setw(2) << right << i
	 << setw(10) << right << factorialIterative(i)
	 << setw(10) << right << factorialRecursive(i) << endl;
  }
  
}
