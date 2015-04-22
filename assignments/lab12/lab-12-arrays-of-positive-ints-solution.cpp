/**
 * @author Derek Harter
 * @cwid   123 45 678
 * @class  CSci 515, Spring 2015
 * @ide    Emacs, GCC/G++
 * @date   April 12, 2015
 * @assg   Lab 12
 *
 * @description Processing arrays of positive ints using a terminating sentinel value
 *    to detect end of elements for processing.
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


/** Determine Length of List of Positive Ints
 * Determine the number of elements in a list of positive integers.  This
 * function expects a pointer to an array of integers that is terminated
 * by a -1 sentinel.  The functions determines the number of
 * positive integers in the list and returns the length of this list
 * as its result.
 *
 * @param posints A pointer to a list/array of positive integers.  The
 *   list should be terminated by a -1 for the last value in the list.
 *
 * @returns int The length of the list of positive integers.
 */
int posintlen(int* posints)
{
  int len = 0;
  while (*posints != -1)
  {
    posints++;
    len++;
  }
  return len;
}


/** Compare two List of Positive Ints
 * We are given two list of positive ints (pointers to -1 terminated
 * arrays of positive integer values).  This function will
 * return 0 if the lists are of the same size and all values in
 * the two lists are equal.  Otherwise, if the first list given
 * comes before the second list, a -1 is returned, otherws a +1
 * will be returned.
 *
 * @param l1 A pointer to a list of positive integers
 * @param l2 A pointer to another list of positive integers
 *   to be compared to l1.
 *
 * @returns int -1 if l1 < l2, +1 if l1 > l2, and 0 if all elements of
 *   l1 == l2
 */
int posintcmp(int* l1, int* l2)
{
  // compare corresponding elements
  while ((*l1 != -1) && (*l2 != -1))
  {
    // if elements are not equal, we have our answer
    if (*l1 < *l2)
    {
      return -1;
    }
    else if (*l1 > *l2)
    {
      return 1;
    }

    // otherwise, go to the next pair of elements to compare
    l1++;
    l2++;
  }

  // at this point, one or both of the lists have been exhausted
  // if both are empty, then the lists are equal
  if ((*l1 == -1) && (*l2 == -1))
  {
    return 0;
  }
  // otherwise, one or the other list was shorter
  else if (*l2 != -1)
  {
    return -1;
  }
  else
  {
    return 1;
  }
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
  // Test the posintlen function
  int l1[] = {5, 3, 8, 2, 7, -1};
  cout << "List 1: ";
  posintprint(l1);
  cout << "Length of List 1: " << posintlen(l1) << endl << endl;

  int l2[] = {-1};
  cout << "List 2: ";
  posintprint(l2);
  cout << "Length of List 2: " << posintlen(l2) << endl << endl;

  // Test the positncmp function
  int l3[] = {4, 2, 9, -1};
  int l4[] = {4, 2, 9, -1};
  cout << "List 3: ";
  posintprint(l3);
  cout << "List 4: ";
  posintprint(l4);
  cout << "Result of posintcmp(list3, list4): " << posintcmp(l3, l4) << endl << endl;

  int l5[] = {4, 2, 7, -1};
  cout << "List 3: ";
  posintprint(l3);
  cout << "List 5: ";
  posintprint(l5);
  cout << "Result of posintcmp(list3, list5): " << posintcmp(l3, l5) << endl;
  cout << "Result of posintcmp(list5, list3): " << posintcmp(l5, l3) << endl;

  // return 0 to indicate successful completion
  return 0;
}
