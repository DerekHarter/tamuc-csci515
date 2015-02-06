/**
 * @author Derek Harter
 * @cwid   123 45 678
 * @class  CSci 515, Spring 2015
 * @ide    Gnu C/C++, Emacs
 * @date   February 5, 2015
 * @assg   Lab 04
 *
 * @description An example solution for the Lab 04.  As specified, we
 *    break the problem up into 2 functions, isPerfectNumber() and
 *    findPerfectNumbers().  This program first asks the user how many
 *    numbers they want to test, and then calls findPerfectNumbers()
 *    to calculate and display the results.
 */
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
using namespace std;


/** find perfect numbers
 * Find all perfect numbers in the range from 1 to n.  n is passed in as a parameter
 * determining how far we should search.  We display the results on standard ouput
 * of the perfect numbers we find.
 *
 * @param int n The maximum number we are to search up to, we will search through
 *    all values from 1 to n
 *
 * @returns void Output is displayed on standard output.
 */
void findPerfectNumbers(int n)
{
  int i;

  // loop through the range we are to search over, looking for perfect numbers
  for (i = 1; i <= n; i++)
  {
    if (isPerfectNumber(i))
    {
      cout << i << " is a perfect number" << endl;
    }
  }
}


/** main entry point
 * The main entry point for this program.  Execution
 * of this program will beigin with this function.
 *
 * @returns An int value.  By default, if we don't specify a return or
 *           exit value, 0 is returned to indicate successful program
 *           completion.  A non-zero value indicates an error or
 *           problem with execution.  Summary information is calculated
 *           while processing the individual lines of input.
 */
int main()
{
  float f;
  float c;

  // ask user for input
  cout << "Enter a value in degrees Fahrenheit, and I will convert it to the Celcius scale:" << endl;
  cin >> f;
  cout << f "degrees Fahrenheit is equal to " << fahrenheitToCelcius(f) << "degress Celcius" << endl;

  // clean up and return 0 to indicate successful completion
  return 0;
}
