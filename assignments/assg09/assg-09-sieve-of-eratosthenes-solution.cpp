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
  cout << "Discovered primes in range 2 to " << size << ": ";
  for (int number = 2; number < size; number++)
  {
    if (isPrime[number])
    {
      cout << number << " ";
    }
  }
  cout << endl;
}


/** multiples of N to false
 * This function takes an array of boolean values (and its size) and
 * some base number called base.  All multiples of this base will
 * be set to false in the boolean array (not including base itself).
 * For example, if base=2, then we will set isPrime[4] = false,
 * isPrime[6] = false, etc.
 *
 * @param isPrime An array of boolean values. 
 * @param size int The size of the array of primes.
 * @param base int The base number that we are to search for
 *   multiples of and set them to false in the array.
 *
 * @returns void.  However, as a side effect all multiples of the
 *   base number will have their values set to false.
 */
void setMultiplesToFalse(bool isPrime[], int size, int base)
{
  int multiple = base + base; // initial multiple to set to false

  // iterate through all the multiples of the base
  while (multiple < size)
  {
    isPrime[multiple] = false;
    multiple += base;
  }
}


/** find primes in range
 * Find all prime numbers in the range from 2 to a given max N.
 * Use the Sieve of Eratosthenes algorithm to search for primes.
 * In this algorithm, we search for multiples of prime numbers
 * and eliminate them as known primes.  This functions takes an
 * array of boolean values, and the size of the array, which also
 * indicates the size N to seach for primes up to.  As a side
 * effect, upon return from this function, all prime number
 * indexes will be set to  true in the boolean array, and all
 * non primes will be false.
 *
 * @param isPrime An array of boolean values, uninitialized.
 * @param size int The size of the array of primes.
 *
 * @returns void.  However, as a side effect when this function
 *   returns all indexes of prime numbers will be true, and all
 *   others will be false.
 */
void sieveOfEratosthenes(bool isPrime[], int size)
{
  // step 1, initialze all elements to true
  initValuesToTrue(isPrime, size);

  // setp 2, iterate through candidates, set multiples of
  // found primes to be false, starting with 2
  for (int prime = 2; prime < size; prime++)
  {
    if (isPrime[prime])
    {
      setMultiplesToFalse(isPrime, size, prime);
    }
  }
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
  const int NUM_PRIMES_TO_TEST = 8400000;
  bool isPrime[NUM_PRIMES_TO_TEST];

  // run the sieve and display results
  sieveOfEratosthenes(isPrime, NUM_PRIMES_TO_TEST);
  displayPrimeNumbers(isPrime, NUM_PRIMES_TO_TEST);

  cout << "sizeof(bool): " << sizeof(bool) << endl;
  cout << "sizeof(isPrime array)" << sizeof(isPrime) << endl;
  // return 0 to indicate successful program completion
  return 0;
}
