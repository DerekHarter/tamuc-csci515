/**
 * @author Derek Harter
 * @cwid   123 45 678
 * @class  CSci 515, Spring 2015
 * @ide    Emacs, GCC/G++
 * @date   May 4, 2015
 * @assg   Lecture 14, P01 Stacks
 *
 * @description Example stack implementation
 *    using self-referential linked-list nodes.
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
  Node headNode;
  Node secondNode;
  Node lastNode;

  // lets create a linked list of 3 integer data values by hand
  headNode.data = 5;
  secondNode.data = 10;
  lastNode.data = 3;
  headNode.nextPtr = &secondNode;
  secondNode.nextPtr = &lastNode;
  lastNode.nextPtr = NULL;

  // lets display them.
  Node* nodePtr = &headNode;

  while (nodePtr != NULL)
  {
    cout << nodePtr->data << " -> ";
    nodePtr = nodePtr->nextPtr;
  }
  cout << "NULL" << endl;
  
  // retun 0 to indicate successful completion
  return 0;
}
