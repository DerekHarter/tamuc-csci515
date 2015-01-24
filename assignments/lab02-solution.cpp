/**
 * @author Derek Harter
 * @cwid   123 45 678
 * @class  CSci 515, Spring 2015
 * @ide    Gnu C++ / Emacs
 * @date   January 22, 2015
 * @assg   Lab 02 Averages of Numbers
 *
 * @description Write a sentenial controlled loop to
 *    prompt user to enter a series of integer numbers.
 *    Perform a series of calculation on the numbers,
 *    including finding their average, min, max, etc.
 *    and display the results.
 */
#include <iostream>
using namespace std;


/** main entry point
 * The main entry point for this program.  Execution
 * of this program will beigin with this function.
 *
 * @returns An int value.  By default, if we don't specify a return or
 *           exit value, 0 is returned to indicate successful program
 *           completion.  A non-zero value indicates an error or
 *           problem with execution.
 */
int main()
{
  int value;
  int count;
  int sum;

  // senteniel controlled loop, allow user to enter values untill they
  // enter -9999 to indicate done
  item = 0;
  count = 0;
  sum = 0;
  cout << "Enter integer values, when done enter -9999." << endl;
  while (item != -9999)
  {
    cout << "Enter next value: ";
    cin >> item;
    if (item != -9999)
    {
      count++;
      sum += item;
    }
  }

  cout << "Number of Values Entered: " << count << endl;
  cout << "Sum of values:" << sum << endl;
  cout << "Maximum value:" << endl;
  cout << "Minimum value:" << endl;
  cout << "Average value:" << endl;

  // return 0 to indicate successful completion
  return 0;
}
