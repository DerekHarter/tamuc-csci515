/**
 * @author
 * @cwid
 * @class  CSci 515, Spring 2015
 * @ide    Visual Studio 2010
 * @date   May 6, 2015
 * @assg   Test 02
 *
 * @description Student submission and answers for Test 02
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;


// Global definitions of structures and constants go here

// Used for tasks 3 and 4
struct Node
{
  int data;
  Node* nextPtr;
};


// Used for task 1
/** Bubble Sort
 * Sort an array of integers using a Bubble sort.  Bubblesort works in
 * this manner.  On the first pass we start at index 0 and compare
 * successive items.  We swap the items if they are out of order.  The
 * result is that on the first pass, the largest item will be "bubbled
 * up" to the largest index.  On the next pass, we do the same thing,
 * but since the last item is alredy bubbled into place, we only pass
 * through the N-1 items.  We do this for N passes.  Bubble sort is
 * very inefficient, it is an O(N^2) algorithm.
 *
 * @param values An array of integers.  The array to be sorted.  The
 *   array is passed by reference and is sorted in place in memory.
 *   The array is sorted in ascending order.
 * @param size int The size of the array to sort.
 *
 * @returns void Nothing is returned explicitly but as a result of
 *   calling this function the array that is passed in will be sorted
 *   into ascending order.
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


/** main entry point
 * The main entry point for this program.  Execution
 * of this program will beigin with this function.
 *
 * Your submission for this test should have only 1 main function.  Your
 * submitted code should be compilable and runable as submitted, and the
 * output you genreate should look like the example output given in
 * your test paper.
 *
 * @returns An int value.  By default, if we don't specify a return or
 *           exit value, 0 is returned to indicate successful program
 *           completion.  A non-zero value indicates an error or
 *           problem with execution.  Summary information is calculated
 *           while processing the individual lines of input.
 */
int main()
{
  // Perform Task 1 here
  cout << "Task 1: array of floats after sorting:" << endl;

  // Perform Task 2 here
  cout << "Task 2: values for item at index 3:" << endl;

  // Perform Task 3 here
  cout << "Task 3: value of node4, accessed through pointer to head node: ";

  // Perform Task 4 here
  cout << "Task 4: value of node5, accessed through pointer to head node: ";

  // Return 0 to indicate program terminated successfully
  return 0;
}
