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
    cout << setw(3) << setfill('0') << idx << ": "
	 << setw(3) << setfill(' ') << values[idx]
	 << endl;
  }
}


/** Display Array
 * Display all of the values in the indicated array of integers.
 *
 * @param values An array of integers.  Arrays are passed by value
 *   so when we initialize this array to random values, the
 *   initialized values will be passed to the caller.
 * @param size int The size of the array to initialize.
 *
 * @returns void.  However, as a side effect we display the
 *   values in the array to standard output.
 */
void displayArray(int values[], int size)
{
  for (int idx = 0; idx < size; idx++)
  {
    cout << setw(3) << setfill('0') << idx << ": "
	 << setw(3) << setfill(' ') << values[idx]
	 << endl;
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
  const int NUM_PRIMES_TO_TEST = 1000;
  bool primes[NUM_PRIMES_TO_TEST];

  initValuesToTrue(primes, NUM_PRIMES_TO_TEST);
  
  // return 0 to indicate successful program completion
  return 0;
}
