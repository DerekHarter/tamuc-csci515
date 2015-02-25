/**
 * @author Derek Harter
 * @cwid   123 45 678
 * @class  CSci 515, Spring 2015
 * @ide    Gnu C/C++, Emacs
 * @date   February 19, 2015
 * @assg   Assg 07
 *
 * @description Implement function to search for and remove duplicates from an
 *   array.
 */
#include <iostream>
#include <iomanip>
using namespace std;



/** Initialize array to random range
 * Initialize an array of integers to values within a random range.
 * We are given the array (and its size), and the begin and end of the
 * range.
 *
 * @param values An array of integers, passed by reference.
 * @param size The size of the array we initializing.
 * @param beginRange An integer, the beginning of the range
 * @param endRange An integer, the end of the range
 *
 * @returns void Nothing is explicitly returned, but as a side effect
 *   of calling this function, the array of values is initialized to
 *   a random value in the range [beginRange, endRange] (inclusive)
 */
void initRandomRange(int values[], int size, int beginRange, int endRange)
{
  // We initialize minimum to the first value, then search values 1..size-1 for smaller ones
  int scale = endRange - beginRange + 1;
  for (int idx = 0; idx < size; idx++)
  {
    values[idx] = (rand() % scale) + beginRange;
  }
}


/** display array
 * Display values in an array in a given range.  We indicate the
 * indices and format the values to give a uniform, nice appearance
 * on standard output.
 *
 * @param values An array of ints, passed by reference.
 * @param size An integer, the number of values in the array.
 *
 * @returns void Results printed to standard output as a side effect.
 */
void displayArray(int values[], int size)
{
  for (int idx = 0; idx < size; idx++)
  {
    cout << "[" << setw(3) << setfill('0') << idx << "] "
	 << setw(5) << setfill(' ') << values[idx] << endl;
  }
}


/** search for value
 * Search the given array for a particular value.  We are given
 * an array of integers (and its size).  We search for a
 * particular value and return True if we find the value in
 * the array, or False otherwise.  This functions correctly
 * handles an empty array as input (e.g. size = 0, we return
 * False, could not find the value in the array).
 *
 * @param values An array of ints, passed by reference.
 * @param size An integer, the number of values in the array.
 * @param valueToSearchFor An integer, the value to search for in
 *   the input array.
 *
 * @returns bool True if the value is found in the array, False
 *   othersies.
 */
bool searchForValue(int values[], int size, int valueToSearchFor)
{
  // We search sequentially for the value
  for (int idx = 0; idx < size; idx++)
  {
    if (values[idx] == valueToSearchFor)
    {
      // the first occurrence we find, we have our answer
      // and we return immediately
      return True;
    }
  }

  // if we look at all the values and get to this point, then
  // we failed to find the value being searched for, so
  // we return a False answer
  return False;
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
  const int ARRAY_SIZE = 10;
  int values[10];
  int uniques[10];

  // initialize to random values
  srand(time(0));
  initRandomRange(values, ARRAY_SIZE, 0, 4);
  cout << "----- Values array (with duplicates):" << endl;
  displayArray(values, ARRAY_SIZE);
  cout << endl;

  //  Return 0 to indicate program terminated successfully
  return 0;
}
