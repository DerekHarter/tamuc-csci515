/**
 * @author Derek Harter
 * @cwid   123 45 678
 * @class  CSci 515, Spring 2015
 * @ide    Gnu C/C++, Emacs
 * @date   May 5, 2015
 * @assg   Test 02
 *
 * @description Example solution of Test 02
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;


// Global definitions of structures and constants
enum Category {HIGH_PERFORMANCE, MID_PERFORMANCE, LOW_PERFORMANCE};
struct Data
{
  float speed;
  int rank;
  Category perfCategory;
};


struct Node
{
  int data;
  Node* nextPtr;
};


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


/** Bubble Sort
 * Sort an array of floats using a Bubble sort.  Sort the array into
 * descending order.  Bubblesort works in this manner.  On the first
 * pass we start at index 0 and compare successive items.  We swap the
 * items if they are out of order.  The result is that on the first
 * pass, the largest item will be "bubbled up" to the largest index.
 * On the next pass, we do the same thing, but since the last item is
 * alredy bubbled into place, we only pass through the N-1 items.  We
 * do this for N passes.  Bubble sort is very inefficient, it is an
 * O(N^2) algorithm.
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
void bubbleSortFloats(float values[], int size)
{
  // outer loop, perform N passes
  for (int pass = 0; pass < size; pass++)
  {
    // inner loop, bubble up items from index 0 up to size-pass-1 index
    for (int idx = 0; idx < (size - pass - 1); idx++)
    {
      // if the values are out of order, swap them
      if (values[idx] < values[idx + 1])
      {
	float tmp = values[idx];
	values[idx] = values[idx + 1];
	values[idx + 1] = tmp;
      }
    }
  }
}


/** Generate Random Data
 * Generate random data for an array of Data structure items.  We
 * are given the array and the size of the array as input.  We generate
 * the data fileds randomly.  
 *
 * @param values An array of Data items.  Array is passed by reference by
 *   default, thus the initializations we make are visible to caller.
 * @param size int The size of the array of Data items.
 *
 * @returns void Nothing is returned explicitly but as a result of
 *   calling this function the array that is passed in will be
 *   initialzied with random data.
 */
void generateData(Data values[], int size)
{
  for (int idx = 0; idx < size; idx++)
  {
    values[idx].speed = ((float)rand() / (float)RAND_MAX) * 10.0;
    values[idx].rank = (rand() % 11);
    Category randCategory = (Category) (rand() % 3); // magic number, bad
    values[idx].perfCategory = randCategory;
  }
}


/** Insert at Back of List
 * Given a linked list, insert the indicated node on the end of the
 * list.
 *
 * @param head A Node*, a pointer to the head of the linked list.
 *   default, thus the initializations we make are visible to caller.
 * @param nodeToInsert A Node*, a pointer to the node to insert on end.
 *
 * @returns void Nothing is returned explicitly but as a result of
 *   calling this function the node will be inserted on the end
 *   of the list by adjusting the pointers of nodes in the list.
 */
void insertAtBack(Node* head, Node* nodeToInsert)
{
  // find the last node in the list
  Node* node = head;
  while (node->nextPtr != NULL)
  {
    node = node->nextPtr;
  }

  // at this point, the node we are pointing to is the last node
  // in the list, so set it to point to the node we are inserting
  // and then make sure that the node we inserted correctly is
  // a NULL pointer node
  node->nextPtr = nodeToInsert;
  nodeToInsert->nextPtr = NULL;
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
  const int TASK1_SIZE = 5;
  float task1Values[TASK1_SIZE] = {-3.8, 4.2, 9.7, -2.5, 5.6};

  bubbleSortFloats(task1Values, TASK1_SIZE);
  cout << "Task 1: array of floats after sorting:" << endl;
  for (int idx=0; idx < TASK1_SIZE; idx++)
  {
    cout << "val[" << idx << "] = " << task1Values[idx] << endl;
  }
  cout << endl;

  // Perform Task 2 here
  const int TASK2_SIZE = 20;
  Data task2Values[TASK2_SIZE];

  srand(time(0));
  generateData(task2Values, TASK2_SIZE);
  cout << "Task 2: values for item at index 3:" << endl;
  cout << "  speed: " << task2Values[3].speed << endl;
  cout << "  rank: " << task2Values[3].rank << endl;
  cout << "  perfCategory: " << task2Values[3].perfCategory << endl;
  cout << endl;

  // Perform Task 3 here
  Node node1;
  Node node2;
  Node node3;
  Node node4;
  Node* head;

  node1.data = 10;
  node2.data = 20;
  node3.data = 30;
  node4.data = 40;
  node1.nextPtr = &node2;
  node2.nextPtr = &node3;
  node3.nextPtr = &node4;
  node4.nextPtr = NULL;

  head = &node1;

  cout << "Task 3: value of node4, accessed through pointer to head node: "
       << head->nextPtr->nextPtr->nextPtr->data << endl << endl;

  // Perform Task 4 here
  Node node5;
  node5.data = 50;
  insertAtBack(head, &node5);
  cout << "Task 4: value of node5, accessed through pointer to head node: "
       << head->nextPtr->nextPtr->nextPtr->nextPtr->data << endl << endl;

  // Return 0 to indicate program terminated successfully
  return 0;
}
