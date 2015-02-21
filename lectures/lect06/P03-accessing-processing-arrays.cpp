/**
 * @author Derek Harter
 * @cwid   123 45 678
 * @class  CSci 515, Spring 2015
 * @ide    Emacs, GCC/G++
 * @date   February 5, 2015
 * @assg   Lecture 06, P03 Processing, accessing and using arrays
 *
 * @description Examples of intializing, and processing values in an array.
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
  // DO NOT use magic numbers in programs, it is good practice
  // to always use a constant to define array size, and iterate over
  // Declare an array
  const int ARRAY_SIZE = 100;
  int c[ARRAY_SIZE];

  // Lets initialize all of the values to 0
  for (int idx = 0; idx < ARRAY_SIZE; idx++)
  {
    c[idx] = 0;
  }

  // Lets initialize all of the values to random integers in range
  // 1 to 20
  for (int idx = 0; idx < ARRAY_SIZE; idx++)
  {
    c[idx] = (rand() % 20) + 1;
  }

  
}
