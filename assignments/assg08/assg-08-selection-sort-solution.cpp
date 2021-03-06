/**
 * @author Derek Harter
 * @cwid   123 45 678
 * @class  CSci 515, Spring 2015
 * @ide    Gnu C/C++, Emacs
 * @date   February 19, 2015
 * @assg   Assg 08
 *
 * @description Implement a selection sort.  A selection sort works
 *   by finding the minimum value in an unsorted subportion of an
 *   array and then swapping this value to the correct location in
 *   the sorted portion of the array.  This implementation creates two
 *   helper functions to perform a lot of the work of the selection
 *   sort.  One function performs the search for the minimum value
 *   in portions of an array.  The other helper function swaps two
 *   locations in an array.
 */
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;



/** Generate Random Integer in Range
 * Generate a random integer.  We generate the integer in the
 * range [beginRange, endRange] inclusive.
 * @param beginRange int The beginning of range inclusive to generate
 *   a random number within.
 * @param endRange int The end of the range for our random numbers.
 *
 * @returns int A random integer in the range [beginRange, endRange]
 */
int randomRange(int beginRange, int endRange)
{
  int scale;

  // Determine the magnitude of the scale between begin and end of range
  scale = endRange - beginRange + 1;

  // Generate the number in range [beginRange, endRange] and return it
  return rand() % scale + beginRange;
}


/** Randomly Initialize Array
 * Initialize an array of integers to random values within
 * some indicated range.  Array is passed by reference, so
 * the initialization of the array elements will be accessible
 * to the caller of this function.
 *
 * @param values An array of integers.  Arrays are passed by value
 *   so when we initialize this array to random values, the
 *   initialized values will be passed to the caller.
 * @param size int The size of the array to initialize.
 * @param beginRange int The beginning of range inclusive to generate
 *   a random number within.
 * @param endRange int The end of the range for our random numbers.
 *
 * @returns void.  However, since arrays are passed by reference,
 *   as a side effect we initialize the array to random values
 *   in range [beginRange, endRange] inclusive and return them.
 */
void initArrayRandomRange(int values[], int size, int beginRange, int endRange)
{
  for (int idx = 0; idx < size; idx++)
  {
    values[idx] = randomRange(beginRange, endRange);
  }
}


/** Display Array
 * Display all of the values in the indicated array of integers.
 *
 * @param values An array of integers.  Arrays are passed by value
 *   so when we initialize this array to random values, the
 *   initialized values will be passed to the caller.
 * @param size int The size of the array to initialize.
 *
 * @returns void.  However, as a side effect we display the
 *   values in the array to standard output.
 */
void displayArray(int values[], int size)
{
  for (int idx = 0; idx < size; idx++)
  {
    cout << setw(3) << setfill('0') << idx << ": "
	 << setw(3) << setfill(' ') << values[idx]
	 << endl;
  }
}


/** Find minimum in subarray
 * Find the minimum vaue in a portion of an array of integers.  We
 * are given the array and its size, and a start index where we
 * are to begin the search from.  We search all values from the start
 * index to the end of the array, and return the location of the
 * minimum integer value as our result.
 *
 * @param values An array of integers.  The array to be sorted.  The
 *   array is passed by reference and is sorted in place in memory.
 *   The array is sorted in ascending order.
 * @param size int The size of the array to sort.
 * @param start int The index to begin searching for the minimum at.
 *
 * @returns int The index/location of the minimum value in the
 *   subportion of the array from start to size-1
 */
int findMinimumInSubarray(int values[], int start, int size)
{
  // first of all, declare that the initial value is the minimum we have seen so far
  int minIndex = start;
  int minValue = values[start];

  // now look at all of the rest of the value in the array and try and find ones
  // that are smaller
  for (int idx = start + 1; idx < size; idx++)
  {
    // if it is smaller than our current minimum, remembre it instead
    if (values[idx] < minValue)
    {
      minValue = values[idx];
      minIndex = idx;
    }
  }

  // return the location where we found the smallest value
  return minIndex;
}


/** Swap array locations
 * Swap two locations in a given array.  We are given two valid
 * indexes into an integer array.  We swap the two values in the
 * indicated locations.  Since the array is passed by reference
 * the result of performing the swap will be visible to the caller
 * after this function returns.
 *
 * @param values An array of integers.  The array to be sorted.  The
 *   array is passed by reference and is sorted in place in memory.
 *   The array is sorted in ascending order.
 * @param loc1 int The first location to be involved in the swap
 * @param loc2 int The other location to be involved in the swap
 *
 * @returns void This function does not return anything explcitly
 *   but as a result of calling this function, values[loc1] and
 *   values[loc2] will be swapped after returning.
 */
void swapArrayLocations(int values[], int loc1, int loc2)
{
  int tmp = values[loc1];
  values[loc1] = values[loc2];
  values[loc2] = tmp;
}


/** Selection Sort
 * Sort an array of integers using a Selection sort.  Selection sort
 * works in the following manner.  We start by considering the entire
 * array to be unsorted.  We find the minimum value in the unsorted
 * portion and swap it into the first location of the unsorted portion
 * of the array.  Now the minimum has been moved to its correct loction
 * and we consider all values after this now sorted value as the now
 * unsorted portion of the array.  Performing N passes of this method
 * will insure all values are found and swapped to their correct location
 * Selection sort is an O(N^2) algorithm.
 *
 * @param values An array of integers.  The array to be sorted.  The
 *   array is passed by reference and is sorted in place in memory.
 *   The array is sorted in ascending order.
 * @param size int The size of the array to sort.
 *
 * @returns void Nothing is returned explicitly but as a result of calling this function the array
 *   that is passed in will be sorted into ascending order.
 */
void selectionSort(int values[], int size)
{
  // perform size passes, to ensure all values get selected and swapped
  // to their correct location
  for (int swapLocation = 0; swapLocation < size; swapLocation++)
  {
    // search for location of minimum value in array from current
    // swapLocation to the end of the array
    int selectedValueLocation = findMinimumInSubarray(values, swapLocation, size);

    // and swap the selected value to the beginning of the unsorted part
    swapArrayLocations(values, swapLocation, selectedValueLocation);
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
  const int NUM_VALUES = 20;
  int values[NUM_VALUES];

  // set seed to a different value based on current time and initialize array to set or random values
  srand(time(0));
  initArrayRandomRange(values, NUM_VALUES, 1, 20);
  cout << "Array, before being sorted:" << endl;
  displayArray(values, NUM_VALUES);
  cout << endl;

  // sort the array using some method
  selectionSort(values, NUM_VALUES);

  // and display it again
  cout << "Array, after being sorted sorted:" << endl;
  displayArray(values, NUM_VALUES);
  cout << endl;

  return 0;
}
