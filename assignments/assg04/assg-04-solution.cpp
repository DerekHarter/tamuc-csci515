/**
 * @author Derek Harter
 * @cwid   123 45 678
 * @class  CSci 515, Spring 2015
 * @ide    Gnu C/C++, Emacs
 * @date   February 5, 2015
 * @assg   Assg 04
 *
 * @description An example solution for the Assg 04.  As specified, we
 *    break the problem up into 2 functions, isPrimeNumber() and
 *    findPrimes().  This program first asks the user for the
 *    beginning and the ending of the range of values to search, and
 *    then calls the function to search for primes within the
 *    indicated range.
 */
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
using namespace std;


/** is perfect number
 * Test whether a given number is a perfect number.
 *
 * @param int number The number to test
 *
 * @returns bool true if the number is a perfect number, false otherwise
 */
bool isPerfectNumber(int number)
{
  int i;
  int sum = 0;
  
  // loop through all values from 1 to number-1 to find divisors
  for (i = 1; i <= number - 1; i++)
  {
    // whenever we find a divisor, add it to the running sum
    if (number % i == 0)
    {
      sum += i;
    }
  }

  // if all the divisors summed up to the original number
  // then it is a perfect number
  if (sum == number)
  {
    return true;
  }
  else
  {
    return false;
  }
}


/** find perfect numbers
 * Find all perfect numbers in the range from 1 to n.  n is passed in as a parameter
 * determining how far we should search.  We display the results on standard ouput
 * of the perfect numbers we find.
 *
 * @param int n The maximum number we are to search up to, we will search through
 *    all values from 1 to n
 *
 * @returns void Output is displayed on standard output.
 */
void findPrimes(int beginRange, int endRange)
{
  int i;

  // loop through the range we are to search over, looking for perfect numbers
  for (i = 1; i <= n; i++)
  {
    if (isPerfectNumber(i))
    {
      cout << i << " is a perfect number" << endl;
    }
  }
}


/** main entry point
 * The main entry point for this program.  Execution
 * of this program will beigin with this function.  Prompt user
 * for begin and end of range to search within for prime numbers.
 *
 * @returns An int value.  By default, if we don't specify a return or
 *           exit value, 0 is returned to indicate successful program
 *           completion.  A non-zero value indicates an error or
 *           problem with execution.  Summary information is calculated
 *           while processing the individual lines of input.
 */
int main()
{
  int beginRange, endRange;

  // ask user for input
  cout << "This program finds all of the prime numbers within a range from M to N." << endl;
  cout << "At what value should we begin searching: ";
  cin >> beginRange;
  cout << "At what value should we end searching: ";
  cin >> endRange;

  // search for primes
  findPrimes(beginRange, endRange);

  // clean up and return 0 to indicate successful completion
  return 0;
}
