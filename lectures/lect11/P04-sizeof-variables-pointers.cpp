/**
 * @author Derek Harter
 * @cwid   123 45 678
 * @class  CSci 515, Spring 2015
 * @ide    Emacs, GCC/G++
 * @date   April 12, 2015
 * @assg   Lecture 11, P04 Sizeof pointers
 *
 * @description Look at size of pointer and other variables.
 */
#include <iostream>
#include <iomanip>
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
  // declare some pointers.
  int a = 7;
  int* aPtr = & a;
  double x = 3.45;
  double* xPtr = &x;
  char c = 'a';
  char* cPtr = &c;

  cout << "sizeof(a) (an int)  : " << sizeof(a) << endl;
  cout << "sizeof(x) (a double): " << sizeof(x) << endl;
  cout << "sizeof(c) (c char)  : " << sizeof(c) << endl;

  cout << "sizeof(aPtr) (a pointer to an int)  : " << sizeof(aPtr) << endl;
  cout << "sizeof(xPtr) (a pointer to a double): " << sizeof(xPtr) << endl;
  cout << "sizeof(cPtr) (a pointer to a char)  : " << sizeof(cPtr) << endl;

  // return 0 to indicate successfull completion.
  return 0;
}
