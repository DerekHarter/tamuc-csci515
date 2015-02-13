/**
 * @author Derek Harter
 * @cwid   123 45 678
 * @class  CSci 515, Spring 2015
 * @ide    Emacs, GCC/G++
 * @date   February 5, 2015
 * @assg   Lecture 04, P02 User Defined Functions
 *
 * @description Call by reference and call by value examples.
 */
#include <iostream>
using namespace std;


/** swap values
 * Swap the values of two given parameters.  An example where pass by reference is needed
 * in order to do the task in a clean and simple manner.  This function does not return
 * a result, the result occurs because we switch the values of the two reference parameters.
 *
 * @param x a reference to an integer value to be swapped with some other
 * @param y a reference to an integer value, the other value to be swapped.
 * 
 * @returns void This function does not return a result.
 */
void swap(int& x, int& y)
{
  int tmp;
  
  tmp = x;
  x = y;
  y = tmp;
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
  int v1 = 32;
  int v2 = 48;

  cout << "Before swapping v1=" << v1 << " v2 = " << v2 << endl;
  swap(v1, v2);
  cout << "After  swapping v1=" << v1 << " v2 = " << v2 << endl;
}
