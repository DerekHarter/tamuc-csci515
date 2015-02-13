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


/** factorial
 * Calculate the factorial of a number n!.  We implement this calculation
 * using an iterative method.
 *
 * @param n An integer value, the number we are to compute the
 *     factorial of.  n must be >= 0.  0! is defined to be 1.
 *
 * @returns int Returns n! = n * n-1 * n-2 * ... * 1
 */
int factorial(int n)
{
  int f = 1;  // the result we will return

  for (int i=1; i <= n; i++)
  {
    f = f * i;
  }

  return f;
}


/** count combinations directly
 * Calculate the number of combinations from a set of n items when
 * choosing i elements from the set.  We use the binomial coefficient
 * to directly calculate the number of combinations that are present.
 *
 * @param n An integer value, the number of items in the set to choose from.
 *     n should be >= 0, a positive number
 * @param i An integer value, the number of elements to choose from the set.
 *     i should be >= 0, a positive value, n choose 0 and n choose n are
 *     defined to have 1 combination.
 *
 * @returns int The number of combinations from choosing i elements from a set of n
 */
int countCombinationsDirectly(int n, int i)
{
  int numCombinations;

  numCombinations = factorial(n) / (factorial(i) * factorial(n - i));

  return numCombinations;
}


/** count combinations recursively
 * Calculate the number of combinations from a set of n items when
 * choosing i elements form the set.  We use the recursive definition
 * of the binomial coefficient to calculate this value recursively.
 *
 * @param n An integer value, the number of items in the set to choose from.
 *     n should be >= 0, a positive number.
 * @param i An integer value, the number of elements to choose from the set.
 *     i should be >=0, a positive value, n choose 0 and n choose n are
 *     defined to have 1 combination.
 *
 * @returns int The number of combinations from choosing i elements from a set of n
 */
int countCombinationsRecursively(int n, int i)
{
  if ((i == 0) || (i == n))
  {
    return 1;
  }
  else
  {
    return countCombinationsRecursively(n-1, i-1) + countCombinationsRecursively(n-1, i);
  }
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
  int i;

  // test factorial
  //for (int i=0; i<=15; i++)
  //{
  //  cout << "Factorial " << i << " : " << factorial(i) << endl;
  //}

  // ask user for the size of set and the number of items to choose
  cout << "Enter n (an integer >= 0), the number of items in a set to choose from: ";
  cin >> n;
  cout << "Enter i (an integer >= 0), the number of elements to select from the set: ";
  cin >> i;

  // Display the results
  cout << "The number of combinations (determined directly)    of " << n << " choose " << i << " is: "
       << countCombinationsDirectly(n, i) << endl;
  cout << "The number of combinations (determined recursively) of " << n << " choose " << i << " is: "
       << countCombinationsRecursively(n, i) << endl;

  // clean up and return 0 to indicate successful completion
  return 0;
}
