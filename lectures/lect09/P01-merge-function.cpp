/**
 * @author Derek Harter
 * @cwid   123 45 678
 * @class  CSci 515, Spring 2015
 * @ide    Emacs, GCC/G++
 * @date   March 13, 2015
 * @assg   Lecture 09, P01 Merge subarrays function.
 *
 * @description Implement function to merge two sorted subportions of an
 *    array.
 */
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

const int MAX_ARRAY_SIZE = 10;

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


/** Merge Subarrays
 * Merge two sorted subportions of an array.  We are given an array, and
 * the begin index, mid index and end index.  The values from begin up
 * to mid-1 are sorted, and the values from mid to end-1 are sorted.  We
 * will merge the two subportions of the array into one.  This can be
 * done linearly, using a temporary bit of storage space.  We copy values
 * from the original array to the temporary storage, taking from subportion
 * low or high as needed.  Once done, we copy the temporary (merged) values
 * back to the original location in our given array.
 *
 * @param values An array of integers.  We expect the contents of the array
 *   to contain two subportions, that are to be merged together.
 * @param begin int The beginning index of the subarray in the array of values
 *   we are to sort.
 * @param mid int The midpoint between the two sorted subportions.  Values
 *   from begin to mid-1 are one subportion of the array, and from mid to
 *   end-1 are the other subportion.
 * @param end int The ending index of the subarray of values to be sorted.
 *
 * @returns void Nothing is returned explicitly but as a result of
 *   calling this function the subportions indicated by begin, mid and
 *   end will be merged into a single sorted subarray.
 */
void merge(int values[], int begin, int end)
{
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
  const int NUM_VALUES = 10;
  int values[NUM_VALUES];

  // set seed to a different value based on current time and
  // initialize array to set or random values
  srand(time(0));
  initArrayRandomRange(values, NUM_VALUES, 1, 20);
  cout << "Array, before being sorted:" << endl;
  displayArray(values, NUM_VALUES);
  cout << endl;

  // sort the array using some method
  mergeSort(values, 0, NUM_VALUES-1);

  // and display it again
  cout << "Array, after being sorted sorted:" << endl;
  displayArray(values, NUM_VALUES);
  cout << endl;

  return 0;
}
