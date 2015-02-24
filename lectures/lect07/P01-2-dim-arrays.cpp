/**
 * @author Derek Harter
 * @cwid   123 45 678
 * @class  CSci 515, Spring 2015
 * @ide    Emacs, GCC/G++
 * @date   February 5, 2015
 * @assg   Lecture 07, P02 Intro to 2-D arrays
 *
 * @description Examples of declaring and initializing a 2-D array
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
  // Declare an array
  int c[10];

  // index an array
  c[0] = 5;
  c[1] = 10;
  c[10] = 22; // ERROR access beyond bounds of array, NO BAD PROGRAMMER

  // loop to initialize an array
  // always, ALWAYS, ALWAYS index starting at 0, up to (but not including)
  // the max value.  Arrays in c are always index from 0 to N-1
  for (int idx = 0; idx < 10; idx++)
  {
    c[idx] = 0;
  }

  // Can use an initializer list when declaring arrays, though not common
  // in real programs
  int d[5] = {0, 1, 2, 3, 4};

  // Basic loop to access first 5 values in c and d
  for (int idx = 0; idx < 5; idx++)
  {
    cout << "c[" << idx << "] = " << c[idx] << " "
	 << "d[" << idx << "] = " << d[idx] << endl;
  }

  // ERROR ERROR Danger Will Robinson!
  // Its is very bad to try and access past the end of an array
  for (int idx = 0; idx < 10; idx++)
  {
    cout << "c[" << idx << "] = " << c[idx] << " "
	 << "d[" << idx << "] = " << d[idx] << endl;
  }

}
