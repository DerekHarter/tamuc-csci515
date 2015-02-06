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
  int n;

  // ask user for input
  cout << "This program finds all of the perfect numbers in the range from 1 to N." << endl;
  cout << "Up to what value of N should I search for perfect numbers: ";
  cin >> n;

  // search for perfect numbers
  findPerfectNumbers(n);
  
  // clean up and return 0 to indicate successful completion
  return 0;
}
