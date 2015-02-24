/**
 * @author Derek Harter
 * @cwid   123 45 678
 * @class  CSci 515, Spring 2015
 * @ide    Emacs, GCC/G++
 * @date   February 5, 2015
 * @assg   Lecture 07, P03 Examples of shifting and moving
 *
 * @description Examples of operations on arrays that add and remove
 *   elements.  Shifting, moving, swapping, adding, deleting.
 */
#include <iostream>
#include <iomanip>
using namespace std;


/** Display Array
 * Display all of the values of an integer array to standard output.
 *
 * @param values An array of integers, allocated but not initialized.
 * @param size The maximum size of the array, an integer value
 *
 * @returns void, but as side effect we display array values to stdout.
 */
void displayArray(int values[], int size)
{
  for (int idx = 0; idx < size; idx++)
  {
    cout << "values[" << setw(3) << setfill('0') << right << idx << "] = "
	 << setw(5) << setfill(' ') << right << values[idx] << endl;
  }
}


/** Initialize Array
 * Initialize all values of the given integer array to the given parameters.  We
 * use a default parameter for the initializer.  By default we initialze the array
 * to 0.  The array is passed by reference, thus our initialization of the array is
 * available to the caller of the functions.
 *
 * @param values An array of integers, allocated but not initialized.  Arrays are
 *    passed by references, so when we initialize the array, all values are
 *    overwritten and the initialized values are passed back to caller.
 * @param size The maximum size of the array, an integer value
 * @param initializer An int value, by defualt we initialize array to 0.
 *
 * @returns void, but as side effect array values is initialized to the initialize
 *    parameter, which is 0 by default.
 */
void initArray(int values[], int size, int initializer = 0)
{
  for (int idx = 0; idx < size; idx++)
  {
    values[idx] = initializer;
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
  // create an array that can potentially hold 20 elements
  const int NUM_VALUES = 20;
  int values[NUM_VALUES];

  // initially whole array is initialize do -9999
  initArray(values, NUM_VALUES, -9999);

  // However, actual number of values is 10, so we can shift things around some
  int size = 10;
  for (int idx = 0; idx < size; idx++)
  {
    values[idx] = idx;
  }
  cout << "Initial Array (with extra space) -------------" << endl;
  cout << "size = " << size << endl;
  displayArray(values, NUM_VALUES);
  cout << endl;
  
  // add an element at index 4
  // first shift elements from 4 up to 5, 5 up to 6, etc
  for (int idx = size; idx >= 5; idx--)
  {
    values[idx] = values[idx - 1]; // shift values up by 1 index
  }
  // do the actual insertion at index 4
  values[4] = 42;
  // and make sure size of array increases, since we have now inserted a value
  size++;
  cout << "Inserted value at index 4 ---------" << endl;
  cout << "size = " << size << endl;
  displayArray(values, NUM_VALUES);
  cout << endl;

  // delete the item at index 8
  // in this case, we can simply shift down item at index 9 to 8, etc.
  for (int idx = 9; idx < size; idx++)
  {
    values[idx - 1] = values[idx];
  }
  // make sure size of array decreases, since we now removed a value
  size--;
  cout << "Deleted value at index 8 -------" << endl;
  cout << " size = " << size << endl;
  displayArray(values, NUM_VALUES);
  cout << endl;

  // ok delete the item at index 3 now, should look similar to previous
  // but I use a variable to hold the initial index
  int deleteIndex = 3;
  for (int idx = deleteIndex + 1; idx < size; idx++)
  {
    values[idx - 1] = values[idx];
  }
  // make sure size of array decreases, since we now removed a value
  size--;
  cout << "Deleted value at index: " << deleteIndex << "-------" << endl;
  cout << " size = " << size << endl;
  displayArray(values, NUM_VALUES);
  cout << endl;
}
