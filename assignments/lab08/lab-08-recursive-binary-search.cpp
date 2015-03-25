/**
 * @author Derek Harter
 * @cwid   123 45 678
 * @class  CSci 515, Spring 2015
 * @ide    Emacs, GCC/G++
 * @date   March 25, 2015
 * @assg   Lab 08
 *
 * @description Implement the binary search as a recursive function call.
 */
#include <iostream>
#include <iomanip>
using namespace std;

const int NOT_FOUND = -1; // indicates a failed search


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


/** Insertion Sort
 * Sort an array of integers using an Insertion sort.  Insertion sort
 * works in this manner.  We first look at the element at index 1.  If
 * it is out of order with element 0, we insert it at index 0.  We
 * then look at the element at index 2 and insert it into the correct
 * location of the sorted part of the list 0-1 by swapping it down
 * until it is at its correct location.  We then repeat by looking at
 * index 3 and inserting into the elements 0-2 by swaping down until
 * it is in order, etc untill we are at the last item.  Insertion sort
 * is very inefficient, it is an O(N^2) algorithm.
 *
 * @param values An array of integers.  The array to be sorted.  The array is passed by reference and
 *   is sorted in place in memory.  The array is sorted in ascending order.
 * @param size int The size of the array to sort.
 *
 * @returns void Nothing is returned explicitly but as a result of calling this function the array
 *   that is passed in will be sorted into ascending order.
 */
void insertionSort(int values[], int size)
{
  int valueToInsert;
  int swapLocation;
  for (int nextIndexToInsert = 1; nextIndexToInsert < size; nextIndexToInsert++)
  {
    valueToInsert = values[nextIndexToInsert];  // store the value we are inserting
    swapLocation = nextIndexToInsert; 

    // test the swapLocation with the item one index lower in the array.  As long as the
    // item we are examining is greater than the value we are trying to insert, we shift
    // it up.  
    while ( (swapLocation > 0) && (values[swapLocation - 1] > valueToInsert) )
    {
      // shift elements one slot
      values[swapLocation] = values[swapLocation - 1];
      swapLocation--;
    }

    // We shifted all of the items up that needed to be moved, now we insert at is
    // correct location
    values[swapLocation] = valueToInsert;
  }
}


/** Recursive Binary Search 
 * Search an array of sorted items using a binary search.  This is
 * a recursive implementation of the search.  This functions
 * takes a sorted array of integers, and the size of the array as
 * input parameters.  This function takes a third value, the item
 * to search for in the array.  The funciton returns the index of
 * the location where the item was found, or NOT_FOUND if the
 * search failed to find the item.
 *
 * @param values An array of integers.  The array to be searched.
 *   This array must be presorted before calling this function, or
 *   else the results will be unpredictable.
 * @param size int The size of the array to sort.
 * @param searchValue int The value to search for in the array.
 *
 * @returns int NOT_FOUND if the search fails, or else the integer
 *   index location of the searchValue in the array.
 */
int binarySearchRecursive(int values[], int low, int high, int searchValue)
{
  // base case, fail if nothing left to search
  if (low > high)
  {
    return NOT_FOUND;
  }

  // calculate midpoint
  mid = (low + high) / 2;

  // base case, successful search
  if (values[mid] == searchValue)
  {
    return mid;
  }

  // recursive cases
  if (searchValue < values[mid])
  {
    return binarySearchRecursive(values, low, mid-1, searchValue)
  }
  else
  {
    return binarySearchRecursive(values, mid+1, high, searchValue)
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
  int searchValue;
  int location;
  
  // set seed to a different value based on current time and initialize array to set or random values
  srand(time(0));
  initArrayRandomRange(values, NUM_VALUES, 1, 20);
  cout << "Array, before being sorted:" << endl;
  displayArray(values, NUM_VALUES);
  cout << endl;

  // sort the array using some method
  insertionSort(values, NUM_VALUES);

  // and display it again
  cout << "Array, after being sorted sorted:" << endl;
  displayArray(values, NUM_VALUES);
  cout << endl;

  cout << "Enter a value and I will search for it in the array: ";
  cin >> searchValue;
  location = binarySearch(values, NUM_VALUES, searchValue);
  if (location == NOT_FOUND)
  {
    cout << "Search failed, value: " << searchValue << " not located in array" << endl;
  }
  else
  {
    cout << "I found the value at location: " << location << endl;
  }

  return 0;
}
