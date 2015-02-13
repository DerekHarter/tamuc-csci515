/**
 * @author Derek Harter
 * @cwid   123 45 678
 * @class  CSci 515, Spring 2015
 * @ide    Gnu C/C++, Emacs
 * @date   February 5, 2015
 * @assg   Assg 05
 *
 * @description Calculate the binomial coefficient, using a direct and 
 *    a recursive algorithm.  The binomial coefficient is a way of counting
 *    the number of combinations when choosing i elements from a set of n items.
 */
#include <iostream>
using namespace std;


/** nth term of Fibonacci series (iterative)
 * Calculate the n^th term of the Fibonacci series.  Implement the
 * calculation using an iterative approach (use a loop).  We take a single
 * integer n as input, which is the term we are to calculate, and return the
 * nth term of the series as an integer for our result.
 *
 * @param n An integer value, the term of the series we are to
 *     caclualte and return.  n must be >= 0, a positive term.
 *
 * @returns int The nth Fibonacci term
 */
int nthFibonacciIterative(int n)
{
}


/** nth term of Fibonacci series (iterative)
 * Calculate the n^th term of the Fibonacci series.  Implement the
 * calculation using an iterative approach (use a loop).  We take a single
 * integer n as input, which is the term we are to calculate, and return the
 * nth term of the series as an integer for our result.
 *
 * @param n An integer value, the term of the series we are to
 *     caclualte and return.  n must be >= 0, a positive term.
 *
 * @returns int The nth Fibonacci term
 */
int nthFibonacciIterative(int n)
{
  int nMinus1;
  int nMinus2;
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

  // Calculate interative the 2,3,...,nth term by adding two previous terms
  nMinus2 = 0;
  nMinus1 = 1;
  for (int i=2; i <= n; i++)
  {
    nthTerm = nMinus1 + nMinus2;

    // remember the two previous terms, for next iteration
    nMinus2 = nMinus1;
    nMinus1 = nthTerm;
  }

  return nthTerm;
}


/** nth term of Fibonacci series (recursive)
 * Calculate the n^th term of the Fibonacci series.  Implement the
 * calculation using a recursive approach.  We take a single
 * integer n as input, which is the term we are to calculate, and return the
 * nth term of the series as an integer for our result.
 *
 * @param n An integer value, the term of the series we are to
 *     caclualte and return.  n must be >= 0, a positive term.
 *
 * @returns int The nth Fibonacci term
 */
int nthFibonacciRecursive(int n)
{
  // The base cases x_0 and x_1
  if (n == 0)
  {
    return 0;
  }
  if (n == 1)
  {
    return 1;
  }

  // otherwise we can calculate recursive
  return nthFibonacciRecursive(n - 1) + nthFibonacciRecursive(n- 2);
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
  int n;

  cout << "Enter n (an integer >= 0), and I will calculate the n^th" << endl
       << "Fibonacci term for you using two different methods: ";
  cin >> n;
  cout << endl;

  cout << n << " term of the Fibonacci series, using iterative method: "
       << nthFibonacciIterative(n) << endl;
  cout << n << " term of the Fibonacci series, using recursive method: "
       << nthFibonacciRecursive(n) << endl;

  // clean up and return 0 to indicate successful completion
  return 0;
}
