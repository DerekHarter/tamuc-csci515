/**
 * @author Derek Harter
 * @cwid   123 45 678
 * @class  CSci 515, Spring 2015
 * @ide    Emacs, GCC/G++
 * @date   February 5, 2015
 * @assg   Lecture 04, P01 Math Library Example
 *
 * @description Demonstration of standard math library functions.
 */
#include <iostream>
#include <iomanip>
#include <cmath> // <---- To use a library of functions, need to include header of function prototypes
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
  // sqrt
  cout << setprecision(16) << showpoint; // show lots of digits, always show them
  cout << "Square root of 4.0 : " << sqrt(4.0) << endl;
  cout << "Square root of 2.0 : " << sqrt(2.0) << endl;
  cout << "Square root of -1.0: " << sqrt(-1.0) << endl;
  cout << endl;

  // some constants defined in the math library
  cout << "pi                 : " << M_PI << endl;
  cout << "e                  : " << M_E << endl;
  cout << endl;

  // raising to a power
  cout << "3^2                : " << pow(3.0, 2.0) << endl;
  cout << "9^0.5              : " << pow(9.0, 0.5) << endl;

  // the exponential functions
  cout << "exp(1.0) e.g. e    : " << exp(1.0);
  cout << endl;

  // floor, ceil, fabs
  cout << "floor of pi        : " << floor(M_PI) << endl;
  cout << "ceiling of e       : " << ceil(M_E) << endl;
  cout << "abs value of -3.25 : " << fabs(-3.251233432) << endl;
  cout << endl;

  // logarithms
  cout << "natural log(e)     : " << log(M_E) << endl;
  cout << "log base 10 of 1000: " << log10(1000.0) << endl;

  // trigonometric functions

  // hyperbolic trig functions

  // etc.
  
  // Return 0 to indicate successful completion
  return 0;
}
