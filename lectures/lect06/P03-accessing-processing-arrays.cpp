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
#include <cstdlib>
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

  // Lets display all of the values in the array
  for (int idx = 0; idx < ARRAY_SIZE; idx++)
  {
    cout << "c[" << idx << "] = " << c[idx] << endl;
  }

  // What is the minimum value in the array?
  int minimum = c[0]; // initialy the smallest we have seen is the first value
  for (int idx = 1; idx < ARRAY_SIZE; idx++) // note where we start search
  {
    if (c[idx] < minimum)
    {
      minimum = c[idx];
    }
  }
  cout << "The minimum value in the array is: " << minimum << endl;

  // Sum up the values in the array, use a variable to keep a running total
  int sum = 0;
  for (int idx = 0; idx < ARRAY_SIZE; idx++)
  {
    sum += c[idx];
  }
  cout << "The sum of the values in the array is: " << sum << endl;
}
