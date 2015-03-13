/**
 * @author Derek Harter
 * @cwid   123 45 678
 * @class  CSci 515, Spring 2015
 * @ide    Emacs, GCC/G++
 * @date   February 5, 2015
 * @assg   Lecture 07, P01 Intro to 2-D arrays
 *
 * @description Examples of declaring and initializing a 2-D array
 */
#include <iostream>
#include <iomanip>
using namespace std;


// constant used as flag to indicated value not found in search
const int NOT_FOUND = -1;


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


/** Linear Search
 * Perform a linear search of an array of integers.  We search for the indicated key
 * and return the index where whe find that key.
 *
 * @param values An array of integers.  The array to be searched.
 * @param size int The size of the array to search
 * @param searchValue in The value to search for
 *
 * @returns int The index in the array where the value is found.  If the
 *   search value is not found in the array, we return NOT_FOUND
 */
int linearSearch(int values[], int size, int searchValue)
{
  // look for first occurence of the searchValue in array using linear search
  for (int idx = 0; idx < size; idx++)
  {
    if (values[idx] == searchValue)
    {
      // we found it, return the location where it was found
      return idx;
    }
  }

  // else we searched everywhere and failed to find it, so return NOT_FOUND
  return NOT_FOUND;
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
  displayArray(values, NUM_VALUES);

  // Let the user search the array:
  int searchValue = 0;
  int index;
  while (searchValue != -9999)
  {
    // get a value to search for
    cout << "Enter a value and I will search for it in the array (-9999 to quit): ";
    cin >> searchValue;

    // stop asking user for more values when they indicate they are done
    if (searchValue == -9999)
    {
      break;
    }

    // search for the indicated value
    index = linearSearch(values, NUM_VALUES, searchValue);
    cout << "The value: " << searchValue;
    if (value == NOT_FOUND)
    {
      cout << " is NOT in the array" << endl;
    }
    else
    {
      cout << " is first found at index: " << index << endl;
    }
  }
}
