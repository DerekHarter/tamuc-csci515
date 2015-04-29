/**
 * @author Derek Harter
 * @cwid   123 45 678
 * @class  CSci 515, Spring 2015
 * @ide    Emacs, GCC/G++
 * @date   April 12, 2015
 * @assg   Lab 13
 *
 * @description Create a function to randomly generate a linked list of integer
 *    values.
 */
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


/** Display a list of positive integers
 * Print out a list of positive integers on standard output. 
 * We are given a pointer to a sentinel terminated array of
 * positive integers.  -1 is used as the sentinel value to 
 * indicate the end of the list.
 *
 * @param posints A pointer to a list/array of positive integers.  The
 *   list should be terminated by a -1 for the last value in the list.
 *
 * @returns void  This function does not reutrn an explicit value, but
 *    as a side effect the give list is formatted and displayed on
 *    standard output.
 */
int posintprint(int* posints)
{
  cout << "{ ";
  while (*posints != -1)
  {
    cout << *posints++;
    if (*posints != -1)
    {
      cout << ", ";
    }
  }
  cout << " }" << endl;
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

  // return 0 to indicate successful completion
  return 0;
}
