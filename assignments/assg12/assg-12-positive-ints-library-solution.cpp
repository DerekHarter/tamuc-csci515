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


/** Copy list of positive ints
 * Copy a list of positive ints from a source to a destination.
 * We are given pointers to arrays of positive ints for the
 * source and destination parameters 1 and 2 respectively.
 * We assume there is enough space available in the dest to hold
 * all of the values from source.  Any existing values in the
 * destination space may be overwritten by this function.
 * This function does not reutrn a result, but after calling
 * all of the values in the source list will be copied to the
 * destination list.
 *
 * @param src A pointer to a list of positive ints.  This list
 *   must be terminated by the -1 sentinel character.  All values
 *   are copied from this source to the destination as a result
 *   of calling this function.
 * @param dest A pointer to enough space to hold a copy of the
 *   source list of positive integers.
 *
 * @returns void Nothing explicit is returned, but as a side
 *   effect after calling this function the dest list will
 *   be overwritten with a copy of the positive integer list
 *   values from the source.
 */
int posintcpy(int* src, int* dest)
{
  while (*src != -1)
  {
    *dest = *src;
    src++;
    dest++;
  }
  *dest = -1; // null terminate the destination, not copied by above loop
}


/** Find value in list of positive ints
 * Search a list of positive ints (using a linear search)
 * for a particular value.  This function is given a
 * sentinel terminated list of positive ints, where -1 is
 * used to indicate the end of the list of values to
 * be searched.
 *
 * @param posints A pointer to an array of integers.  This list
 *   must be terminated by the -1 sentinel character.  We search
 *   this list for the search value.
 * @param int searchValue The value to search for in the list.
 *   The index of the first location containing this value is
 *   returned.
 *
 * @returns int The index of the first location of the search
 *   value, or -1 if not found.
 */
int posintfind(int* posints, int searchValue)
{
  int pos = 0;

  // since we need to return the position/index,
  // we use an explicit index variable, but notice
  // that our test condition stops when we find the
  // sentinel character
  for (int idx = 0; posints[idx] != -1; idx++)
  {
    if (posints[idx] == searchValue)
    {
      return idx;
    }
  }

  // if we get past the above loop then search failed,
  // so return failure indicator
  return -1; 
}


/** Concatenate lists of positive ints
 * Concatenate the values in the source list
 * of positive integers on to the end of the 
 * destination list.  Both lists should be
 * sentinel terminated lists of positive integers
 * where -1 is the terminating sentinel value.  The
 * destination list should have enough space allocated
 * so that it can successfully be expaneded to
 * hold the extra values fromt he src list.
 *
 * @param src A list of positive integers that is
 *   terminated by the -1 sentinel character.  We append
 *   this list to the end of the destination list.
 * @param dest A list of positive integers.  Values
 *   are appended to the end of this list.  The memory
 *   pointed to by this pointer must be big enough
 *   to hold all the appended values from the source.
 *
 * @returns void Nothing explicit is returned, but
 *   after claling this function all values from
 *   the source list will be appended to the
 *   destination.
 */
void posintcat(int* src, int* dest)
{
  // first need to find end of the dest to
  // begin copying values
  int pos = posintlen(dest);
  // example of pointer arithmetic, length gives
  // offset where the terminal sentinel is positioned
  dest = dest + pos;

  // Now we can simply use the cpy function to copy
  // the src to this destination at the end of the string
  posintcpy(src, dest);
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
  // Test the positncmp function on lists of unequal size
  int l1[] = {4, 2, 7, -1};
  int l2[] = {4, 2, 7, 3, -1};
  cout << "List 1: ";
  posintprint(l1);
  cout << "List 2: ";
  posintprint(l2);
  cout << "Result of posintcmp(list1, list2): " << posintcmp(l1, l2) << endl;
  cout << "Result of posintcmp(list2, list1): " << posintcmp(l2, l1) << endl;
  cout << endl;

  // Test the posintcpy function
  int l3[10] = {-1};; // a buffer of 10 integers
  cout << "List 3 (an empty list with enoough room to hold 10 values): ";
  posintprint(l3);
  posintcpy(l2, l3);
  cout << "After copy of list2 to list3, list3 = ";
  posintprint(l3);
  cout << endl;

  // Test the posintfind function
  cout << "Result of searching for 4 in List 2: " << posintfind(l2, 4) << endl;
  cout << "Result of searching for 7 in List 2: " << posintfind(l2, 7) << endl;
  cout << "Result of searching for 8 in List 2: " << posintfind(l2, 8) << endl;
  cout << endl;

  // Test the posintcat function
  int l4[10] = {9, 10, 15, 22, -1};
  cout << "List 4 has enough room for 10 values, but currently contains only 4: ";
  posintprint(l4);
  cout << "Result of concatenating List 2 onto end of List 4: ";
  posintcat(l2, l4);
  posintprint(l4);
  cout << endl;
  
  // return 0 to indicate successful completion
  return 0;
}
