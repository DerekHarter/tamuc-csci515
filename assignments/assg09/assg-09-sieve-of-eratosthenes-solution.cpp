/**
 * @author Derek Harter
 * @cwid   123 45 678
 * @class  CSci 515, Spring 2015
 * @ide    Gnu C/C++, Emacs
 * @date   February 19, 2015
 * @assg   Assg 09
 *
 * @description Implement the Sieve of Eratosthenes algorithm.  This algorithm will find all
 *    the prime numbers in the range from 2 to N for a given value of N.
 */
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;


/** Init bool array to true 
 * Initialize an array of boolean values to all true.  We are given an
 * array of booleans, and the size of the array.
 *
 * @param values An array of bool.  Arrays are passed by value so when
 *   we initialize this array the initialized values will be passed to
 *   the caller.
 * @param size int The size of the array to initialize.
 *
 * @returns void.  However, as a side effect we initialize the array
 *   of boolean values to all be true.
 */
void initValuesToTrue(bool values[], int size)
{
  for (int idx = 0; idx < size; idx++)
  {
    values[idx] = true;
  }
}


/** Display primes
 * Display discovered primes.  This function expects an array of
 * booleans and this arrays size as its parameters.  This function
 * will be called after an algorithm has been turn that sets the index
 * of all prime numbers in the boolean array to true, and all other
 * indexes to false.  This function displays the list of discovered
 * prime numbers to standard output.
 *
 * @param isPrime An array of boolean values.  All true values
 *   in the array represent index/integers that are prime.  All
 *   false values are non-primes.  We only display the prime numbers.
 * @param size int The size of the array of primes.
 *
 * @returns void.  However, as a side effect we display all of the
 *   prime integers indicated by the passed in primes bool array.
 */
void displayPrimeNumbers(bool isPrime[], int size)
{
  cout << "Discovered primes in range 2 to " << size << ": "
  for (int number = 2; number < size; number++)
  {
    if (isPrime[number])
    {
      cout << number << " ";
    }
  }
  cout << endl;
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
  const int NUM_PRIMES_TO_TEST = 10;
  bool isPrime[NUM_PRIMES_TO_TEST];

  initValuesToTrue(isPrime, NUM_PRIMES_TO_TEST);
  displayPrimeNumbers(isPrime, NUM_PRIMES_TO_TEST);
  
  // return 0 to indicate successful program completion
  return 0;
}
