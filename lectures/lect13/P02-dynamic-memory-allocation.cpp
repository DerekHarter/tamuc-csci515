/**
 * @author Derek Harter
 * @cwid   123 45 678
 * @class  CSci 515, Spring 2015
 * @ide    Emacs, GCC/G++
 * @date   April 12, 2015
 * @assg   Lecture 13, P02 Examples of allocating memory dynamically
 *
 * @description Example of allocating memory dynamically using new
 *    operator, and deallocating using the delete operator.
 */
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;


// A self-referential structure
struct Node
{
  int data;
  Node* nextPtr;
};


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
  // We can dynamically allocate built-in data types, if we want...
  float* fPtr;
  fPtr = new float();
  *fPtr = 4.3;
  cout << "Value of dynamically created float: " << *fPtr << endl;
  cout << "Memory address of float: " << fPtr << endl;

  // and deallocate it
  delete fPtr;
  //cout << "Value of dynamically created float (after deallocation): " << *fPtr << endl;
  //cout << "Memory address of float: " << fPtr << endl;

  // lets create a linked list of 3 integer data items using dynamic allocation.
  Node* headNode;
  Node* secondNode;
  Node* lastNode;

  // set up the nodes
  headNode = new Node();
  headNode->data = 5;

  secondNode = new Node();
  secondNode->data = 10;

  lastNode = new Node();
  lastNode->data = 3;

  // set up the linked list of nodes
  headNode->nextPtr = secondNode;
  secondNode->nextPtr = lastNode;
  lastNode->nextPtr = NULL;

  // lets display them.
  Node* nodePtr = headNode;

  while (nodePtr != NULL)
  {
    cout << nodePtr->data << " -> ";
    nodePtr = nodePtr->nextPtr;
  }
  cout << "NULL" << endl;

  // retun 0 to indicate successful completion
  return 0;
}
