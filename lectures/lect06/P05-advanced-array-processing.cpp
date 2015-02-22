/**
 * @author Derek Harter
 * @cwid   123 45 678
 * @class  CSci 515, Spring 2015
 * @ide    Emacs, GCC/G++
 * @date   February 5, 2015
 * @assg   Lecture 06, P04 Advanced Array Processing
 *
 * @description Some examples of some more advanced array processing.  The dice throwing
 *   game simulation.  Simulate throwing a pair of dice.  Count up the number of the sums
 *   we observe.  Display as a crude histogram.  Show example of a normal distribution as the
 *   result of many small uniform distributions that are summed.
 */
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;


/** Display Array
 * Display all of the values of an integer array to standard output.
 *
 * @param values An array of integers, allocated but not initialized.
 * @param size The maximum size of the array, an integer value
 *
 * @returns void, but as side effect we display array values to stdout.
 */
void displayArray(int values[], int size)
{
  for (int idx = 0; idx < size; idx++)
  {
    cout << "values[" << setw(3) << setfill('0') << right << idx << "] = "
	 << setw(5) << setfill(' ') << right << values[idx] << endl;
  }
}


/** Initialize Array
 * Initialize all values of the given integer array to the given parameters.  We
 * use a default parameter for the initializer.  By default we initialze the array
 * to 0.  The array is passed by reference, thus our initialization of the array is
 * available to the caller of the functions.
 *
 * @param values An array of integers, allocated but not initialized.  Arrays are
 *    passed by references, so when we initialize the array, all values are
 *    overwritten and the initialized values are passed back to caller.
 * @param size The maximum size of the array, an integer value
 * @param initializer An int value, by defualt we initialize array to 0.
 *
 * @returns void, but as side effect array values is initialized to the initialize
 *    parameter, which is 0 by default.
 */
void initArray(int values[], int size, int initializer = 0)
{
  for (int idx = 0; idx < size; idx++)
  {
    values[idx] = initializer;
  }
}


/** random integer in range
 * Create a random integer in the range from beginRange to endRange
 * (inclusive)
 *
 * @param beginRange an integer, the beginning of the range within
 *    which to generate a random number
 * @param endRange an integer, the end of the range
 *
 * @returns An int value.  A number in range [beginRange, endRange]
 *    inclusive
 */
int randomRange(int beginRange, int endRange)
{
  int scale = endRange - beginRange + 1;
  int val = rand() % scale; // value in range 0 to scale
  return val + beginRange; // return value in range beginRange to endRange
}


/** Initialize Array to Random Value
 * Initialize all values of the given integer array to a random value.
 * We are given the begin and end range of the values (inclusive) which
 * specify the range of the random number we are to generate.  Arrays are
 * passed by reference, thus our initialization of the array to random
 * values will be passed back and available to the caller.
 *
 * @param values An array of integers, allocated but not initialized.  Arrays are
 *    passed by references, so when we initialize the array, all values are
 *    overwritten and passed back to caller.
 * @param size The maximum size of the array, an integer value
 * @param beginRange an integer value, the beginning of the range we are to use
 *    when generating random initial values (inclusive).
 * @param endRange an integer value, the end of the range we are to use
 *    when generating random initial values (inclusive)
 *
 * @returns void, but as side effect array values are initialized to a random
 *    integer in the range [beginRange, endRange] inclusive.
 */
void initArrayToRandomRange(int values[], int size, int beginRange, int endRange)
{
  for (int idx = 0; idx < size; idx++)
  {
    values[idx] = randomRange(beginRange, endRange);
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
  // Array to hold a series of simulated random dice throws
  const int NUM_TRIALS = 3;
  int dice1[NUM_TRIALS];
  int dice2[NUM_TRIALS];

  // roll random dice
  srand(time(0)); // initialize to different starting seed based on current time
  initArrayToRandomRange(dice1, NUM_TRIALS, 1, 6);
  initArrayToRandomRange(dice2, NUM_TRIALS, 1, 6);

  // display the results
  cout << "----- Dice 1, trials 1 to N" << endl;
  displayArray(dice1, NUM_TRIALS);
  cout << "----- Dice 2, trials 1 to N" << endl;
  displayArray(dice2, NUM_TRIALS);

}
