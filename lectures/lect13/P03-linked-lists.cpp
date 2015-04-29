/**
 * @author Derek Harter
 * @cwid   123 45 678
 * @class  CSci 515, Spring 2015
 * @ide    Emacs, GCC/G++
 * @date   April 12, 2015
 * @assg   Lecture 13, P03 Examples of developing linked list and functions
 *
 * @description Example of linked list and functions to create and manipulate.
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


/** construct new node
 * construct a new integer node
 *
 * @param data The data item for the new node
 *
 * @returns A Node* the newly (dynamically created) Node.
 */
Node* constructNode(int data)
{
  Node* newNodePtr = new Node();

  // initialze the new node values
  newNodePtr->data = data;
  newNodePtr->nextPtr = NULL;

  return newNodePtr;
}


/** insert node at fron of list
 * Insert node at front of list
 *
 * @param list A  Node* to an existing list (or NULL if list is empty)
 * @param nodePtr A Node* to a new single item to insert at front of list.
 *
 * @returns 
 */
Node* insertAtFront(Node* list, Node* nodePtr)
{
  if (list == NULL)
  {
    list = nodePtr;
    nodePtr->nextPtr = NULL;
  }
  else
  {
    nodePtr->nextPtr = list;
    list = nodePtr;
  }

  return list;
}


/** disply a list
 * Display a linked list of intger nodes
 *
 * @param list A  Node* to the head node of a list of integers
 *
 * @returns void, but displays list values on standard output
 */
Node* displayList(Node* list)
{
  Node* nodePtr = list;

  while (nodePtr != NULL)
  {
    cout << nodePtr->data << " -> ";
    nodePtr = nodePtr->nextPtr;
  }
  cout << "EOL" << endl;

  return list;
}


/** remove last node
 * Remove node from end of list and deallocate the nodes memory.
 *
 * @param list A  Node* to an existing list (or NULL if list is empty)
 *
 * @returns Node* The head pointer to the resulting list (if list becomes empty, needed).
 */
Node* removeFromBack(Node* list)
{
  // first find the last item in list, keeping track of it and its predecessor
  Node* nodePtr = list;

  if (nodePtr->nextPtr == NULL)
  {
    delete list;
    list = NULL;
  }
  else
  {
    while (nodePtr->nextPtr->nextPtr != NULL)
    {
      nodePtr = nodePtr->nextPtr;
    }
  
    // now we need to update list, and delete last item
    delete nodePtr->nextPtr;  // first deallocate the last node we found
    nodePtr->nextPtr = NULL;
  }

  return list;
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
  // function to create a new node
  Node* node1 = constructNode(8);
  Node* node2 = constructNode(16);
  Node* node3;

  node3 = constructNode(32);

  cout << "Node 2 value: " << node2->data << endl;

  // function to insert at front
  Node* listPtr = NULL;
  cout << "An empty list:" << endl;
  displayList(listPtr);
  cout << endl;

  listPtr = insertAtFront(listPtr, node1);
  cout << "After inserting node1 at front: " << endl;
  displayList(listPtr);

  listPtr = insertAtFront(listPtr, node2);
  cout << "After inserting node2 at front: " << endl;
  displayList(listPtr);

  listPtr = insertAtFront(listPtr, node3);
  cout << "After inserting node3 at front: " << endl;
  displayList(listPtr);

  // function to remove from front

  // function to insert at back

  // function to remove from back
  cout << "Test removal of last item now:" << endl;
  listPtr = removeFromBack(listPtr);
  displayList(listPtr);

  cout << "Test removal of last item now:" << endl;
  listPtr = removeFromBack(listPtr);
  displayList(listPtr);

  cout << "Test removal of last item now:" << endl;
  listPtr = removeFromBack(listPtr);
  displayList(listPtr);

  // retun 0 to indicate successful completion
  return 0;
}
