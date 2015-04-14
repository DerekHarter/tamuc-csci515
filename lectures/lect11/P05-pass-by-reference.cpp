/**
 * @author Derek Harter
 * @cwid   123 45 678
 * @class  CSci 515, Spring 2015
 * @ide    Emacs, GCC/G++
 * @date   April 12, 2015
 * @assg   Lecture 11, P05 Pass by reference using pointers
 *
 * @description Look at passing by reference using pointers.
 */
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;


/** Swap using Reference Parameters
 * An example of passing values by reference using reference parameters.
 * Here the purpose is to swap the location in memory of the given 2 values.
 *
 * @param x A reference parameter to some integer in memory.
 * @param y A reference parameter to a different integer in memory.
 *
 * @returns void, but as a side effect the x and y integers will be swapped
 *           after calling this function.
 */
void swapRef(int& x, int& y)
{
  int tmp = x;
  x = y;
  y = tmp;
}


/** Swap using Pointers
 * An example of passing values by reference using pointer variables.
 * Here the purpose is to swap the location in memory of the given 2 values.
 *
 * @param x A pointer to some integer in memory.
 * @param y A pointer to a different integer in memory.
 *
 * @returns void, but as a side effect the integers pointed to by x
 *           and y will be swapped after calling this function.
 */
void swapPtr(int* x, int* y)
{
  int tmp = *x;
  *x = *y;
  *y = tmp;
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
  int i1 = 10;
  int i2 = 2;

  swapRef(i1, i2);
  cout << "After swap using reference paramters: i1=" << i1 << " i2=" << i2 << endl;

  swapPtr(&i1, &i2);
  cout << "After swap using pointer variables  : i1=" << i1 << " i2=" << i2 << endl;
  
  // return 0 to indicate successfull completion.
  return 0;
}
