/**
 * @author Derek Harter
 * @cwid   123 45 678
 * @class  CSci 515, Spring 2015
 * @ide    Emacs, GCC/G++
 * @date   March 13, 2015
 * @assg   Lecture 09, P02 Merge Sort
 *
 * @description An implementation of the Merge Sort
 */
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;


const int MAX_ARRAY_SIZE = 10;

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
void merge(int values[], int begin, int mid, int end)
{
  int tmpStorage[MAX_ARRAY_SIZE];
  int size;
  int lowerIndex;
  int upperIndex;
  int tmpIndex;

  // We iterate through the temporary storage from 0 to size-1 of
  // the combined subarrays.  We copy either from the lower subarray
  // or the upper subarray as appropriate
  lowerIndex = begin;
  upperIndex = mid;
  size = end - begin;  // size of combined lower and upper subarrays
  for (tmpIndex = 0; tmpIndex < size; tmpIndex++)
  {
    // if lower subarray already copied, get next item from upper array
    if (lowerIndex == mid)
    {
      tmpStorage[tmpIndex] = values[upperIndex++];
    }
    // else if upper subarray already copied, get next item from lower array
    else if (upperIndex == end)
    {
      tmpStorage[tmpIndex] = values[lowerIndex++];
    }
    // else get next item based on comparing which item is smallest at
    // the current location of the lower and upper parts
    else if (values[lowerIndex] < values[upperIndex])
    {
      tmpStorage[tmpIndex] = values[lowerIndex++];
    }
    else
    {
      tmpStorage[tmpIndex] = values[upperIndex++];
    }
  }

  // After above, we have merged to temporay storage, so now copy back
  // to original storage
  lowerIndex = begin;
  for (tmpIndex = 0, lowerIndex = begin; tmpIndex < size; tmpIndex++, lowerIndex++)
  {
    values[lowerIndex] = tmpStorage[tmpIndex];
  }
}


/** Merge Sort
 * Sort an array of integers using a merge sort.  
 *
 * @param values An array of integers.  The array to be sorted.  The
 *   array is passed by reference and is sorted in place in memory.
 *   The array is sorted in ascending order.
 * @param begin int The beginning element/index of the subarray in the
 *   array of values we are to sort.  @param end int The ending
 *   element/index of the subarray in the array of values.
 *
 * @returns void Nothing is returned explicitly but as a result of
 *   calling this function the array that is passed in will be sorted
 *   into ascending order.
 */
void mergeSort(int values[], int begin, int end)
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
