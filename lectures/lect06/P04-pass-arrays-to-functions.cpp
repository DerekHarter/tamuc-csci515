/**
 * @author Derek Harter
 * @cwid   123 45 678
 * @class  CSci 515, Spring 2015
 * @ide    Emacs, GCC/G++
 * @date   February 5, 2015
 * @assg   Lecture 06, P04 arrays as function parameters
 *
 * @description Passing arrays to functions as parameters.  Using functions to initialize
 *    and process arrays.
 */
#include <iostream>
#include <iomanip>
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
  const int ARRAY_SIZE = 10;
  int values[ARRAY_SIZE];

}