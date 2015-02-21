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
using namespace std;

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
  const int ARRAY_SIZE = 100;
  int values[ARRAY_SIZE];

  // Lets initialize the array with values in 0 to 50
  // but with an unequal distribution (sum of 5 random numbers in range 0-10)
  for (int idx = 0; idx < ARRAY_SIZE; idx++)
  {
    int sum = 0;
    for (int r = 1; r <= 5; r++)
    {
      sum += randomRange(0, 10);
    }
  }
}
