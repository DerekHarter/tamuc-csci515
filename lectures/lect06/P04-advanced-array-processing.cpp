/**
 * @author Derek Harter
 * @cwid   123 45 678
 * @class  CSci 515, Spring 2015
 * @ide    Emacs, GCC/G++
 * @date   February 5, 2015
 * @assg   Lecture 06, P04 Advanced Array Processing
 *
 * @description Some examples of some more advanced array processing.
 */
#include <iostream>
#include <cstdlib>
using namespace std;


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
  const int ARRAY_SIZE = 1000;
  int values[ARRAY_SIZE];

  // Lets initialize the array with values in 0 to 9
  // but with an unequal distribution (sum of 5 random numbers in range 0-10)
  for (int idx = 0; idx < ARRAY_SIZE; idx++)
  {
    int sum = 0;
    for (int r = 1; r <=3; r++)
    {
      sum += randomRange(0, 3);
    }
    values[idx] = sum;
  }

  // Create another array to count items with value 0,1,2,...,9
  const int MAX_VALUE = 10;
  int hist[MAX_VALUE];

  // initialize array to 0
  for (int idx = 0; idx < MAX_VALUE; idx++)
  {
    hist[idx] = 0;
  }

  // count frequence of values
  for (int idx = 0; idx < ARRAY_SIZE; idx++)
  {
    hist[values[idx]] += 1;
  }

  // Display a histogram of the frequency
  for (int idx = 0; idx < MAX_VALUE; idx++)
  {
    // output bar label
    cout << idx << ":";

    // print bar of astericks to represent historgam
    for (int stars = 0; stars < hist[idx]; stars++)
    {
      cout << "*";
    }
    cout << endl;
  }
}
