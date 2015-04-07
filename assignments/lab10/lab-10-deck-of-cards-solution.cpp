/**
 * @author Derek Harter
 * @cwid   123 45 678
 * @class  CSci 515, Spring 2015
 * @ide    Emacs, GCC/G++
 * @date   March 25, 2015
 * @assg   Lab 10
 *
 * @description Simulate creation of a deck of cards.  Demonstrate user
 *    defined data types for a Card, and create an array of such Card types.
 */
#include <iostream>
#include <iomanip>
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
  // test V1 bubble sort optimizations
  const int NUM_VALUES = 8;
  int almostSorted1[NUM_VALUES] = {3, 5, 13, 9, 18, 11, 10, 15};

  cout << "Before calling bubbleSortV1:" << endl;
  displayArray(almostSorted1, NUM_VALUES);
  cout << endl;

  bubbleSortV1(almostSorted1, NUM_VALUES);
  cout << endl;

  cout << "After calling bubbleSortV1:" << endl;
  displayArray(almostSorted1, NUM_VALUES);
  cout << endl;

  // test V2 bubble sort optimizations
  int almostSorted2[NUM_VALUES] = {7, 5, 3, 9, 10, 11, 15, 18};

  cout << "Before calling bubbleSortV2:" << endl;
  displayArray(almostSorted2, NUM_VALUES);
  cout << endl;

  bubbleSortV2(almostSorted2, NUM_VALUES);
  cout << endl;

  cout << "After calling bubbleSortV2:" << endl;
  displayArray(almostSorted2, NUM_VALUES);
  cout << endl;

  // return 0 to indicate successful completion.
  return 0;
}
