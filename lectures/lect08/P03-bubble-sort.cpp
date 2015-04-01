/**
 * @author Derek Harter
 * @cwid   123 45 678
 * @class  CSci 515, Spring 2015
 * @ide    Emacs, GCC/G++
 * @date   March 13, 2015
 * @assg   Lecture 08, P03 Bubble Sort
 *
 * @description An implementation of various sorting algorithms.
 */
#include <iostream>
#include <iomanip>
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


/** Bubble Sort
 * Sort an array of integers using a Bubble sort.  Bubblesort works in this manner.
 * On the first pass we start at index 0 and compare successive items.  We
 * swap the items if they are out of order.  The result is that on the first
 * pass, the largest item will be "bubbled up" to the largest index.  On the
 * next pass, we do the same thing, but since the last item is alredy bubbled
 * into place, we only pass through the N-1 items.  We do this for N passes.
 * Bubble sort is very inefficient, it is an O(N^2) algorithm.
 *
 * @param values An array of integers.  The array to be sorted.  The array is passed by reference and
 *   is sorted in place in memory.  The array is sorted in ascending order.
 * @param size int The size of the array to sort.
 *
 * @returns void Nothing is returned explicitly but as a result of calling this function the array
 *   that is passed in will be sorted into ascending order.
 */
void bubbleSort(int values[], int size)
{
  // outer loop, perform N passes
  for (int pass = 0; pass < size; pass++)
  {
    // inner loop, bubble up items from index 0 up to size-pass-1 index
    for (int idx = 0; idx < (size - pass - 1); idx++)
    {
      // if the values are out of order, swap them
      if (values[idx] > values[idx + 1])
      {
	int tmp = values[idx];
	values[idx] = values[idx + 1];
	values[idx + 1] = tmp;
      }
    }
  }
}


/** Bubble Sort v2
 * Sort an array of integers using a Bubble sort.  In this second version we add the following
 * optimization.  Within the inner iteration/pass through the array, we keep track of how
 * many swaps are performed.  If, after completing this inner loop, we ended up not performing
 * any swaps, it means we have detected that the array is sorted, thus we terminate early.
 *
 * @param values An array of integers.  The array to be sorted.  The array is passed by reference and
 *   is sorted in place in memory.  The array is sorted in ascending order.
 * @param size int The size of the array to sort.
 *
 * @returns void Nothing is returned explicitly but as a result of calling this function the array
 *   that is passed in will be sorted into ascending order.
 */
void bubbleSort2(int values[], int size)
{
  // outer loop, perform N passes
  for (int pass = 0; pass < size; pass++)
  {
    // inner loop, bubble up items from index 0 up to size-pass-1 index
    for (int idx = 0; idx < (size - pass - 1); idx++)
    {
      // if the values are out of order, swap them
      if (values[idx] > values[idx + 1])
      {
	int tmp = values[idx];
	values[idx] = values[idx + 1];
	values[idx + 1] = tmp;
      }
    }
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
  const int NUM_VALUES = 10;
  int values[NUM_VALUES];

  // set seed to a different value based on current time and initialize array to set or random values
  srand(time(0));
  initArrayRandomRange(values, NUM_VALUES, 1, 20);
  cout << "Array, before being sorted:" << endl;
  displayArray(values, NUM_VALUES);
  cout << endl;

  // sort the array using some method
  bubbleSort(values, NUM_VALUES);

  // and display it again
  cout << "Array, after being sorted sorted:" << endl;
  displayArray(values, NUM_VALUES);
  cout << endl;

  return 0;
}
