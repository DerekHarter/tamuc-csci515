/**
 * @author Derek Harter
 * @cwid   123 45 678
 * @class  CSci 515, Spring 2015
 * @ide    Emacs, GCC/G++
 * @date   February 5, 2015
 * @assg   Lecture 06, P02 Array declarations and indexing
 *
 * @description Using const declarations to avoid MAGIC NUMBERS
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
  const int ARRAY_SIZE = 10;
  int c[ARRAY_SIZE];

  // loop to initialize an array
  // always, ALWAYS, ALWAYs index starting at 0, up to (but not including)
  // the max value.  Arrays in c are always index from 0 to N-1
  for (int idx = 0; idx < ARRAY_SIZE; idx++)
  {
    c[idx] = idx;
  }

  // index an array
  c[0] = 5;
  c[1] = 10;
  c[ARRAY_SIZE - 2] = 42;

  // what do we have in the array now?
  for (int idx = 0; idx < ARRAY_SIZE; idx++)
  {
    cout << "c[" << idx << "] = " << c[idx] << endl;
  }
}
