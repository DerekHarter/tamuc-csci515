/**
 * @author Derek Harter
 * @cwid   123 45 678
 * @class  CSci 515, Spring 2015
 * @ide    Emacs, GCC/G++
 * @date   April 12, 2015
 * @assg   Assg 13 Linked List Processing
 *
 * @description Example functions to process linked lists of integer data.
 *    values.
 */
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;


// The node structure, basic structure used to create
// linked lists of integer items
struct Node
{
  int data;
  Node* nextPtr;
};


/** Construct New Node
 * Dynamically allocate memory for a new Node holding an
 * integer data item, and return a pointer to this
 * newly allocated structure.
 *
 * @param data An integer, the value to be stored in this
 *   newly constructed node.
 *
 * @returns Node* A pointer to the Node item we just
 *   dynamically created and initialized.
 */
Node* newNode(int data)
{
  Node* nodePtr = new Node();
  nodePtr->data = data;
  nodePtr->nextPtr = NULL;
  return nodePtr;
}


/** Generate Random List
 * Generate and return a linked list of nodes.  The values
 * contained in the nodes will be randomly generated integers
 * in the range from 1 to 20.  We are given a parameter,
 * numNodes, which indicates how many nodes we should create and add
 * to the linked list.  We return a pointer to the head node
 * of the newly dynamically allocated list of integer items.
 *
 * @param numNodes An integer, the number of nodes we are to
 *   create in our randomly generated list of integer nodes.
 *   This function assumes numNodes >= 1, it will not generate
 *   an empty list.
 *
 * @returns Node* A pointer to the head node of the linked
 *    list of integers we create.
 */
Node* generateRandomList(int numNodes)
{
  Node* headPtr = NULL;
  int data = (rand() % 20) + 1;

  // create the head node, to be returned by this function
  headPtr = newNode(data);

  // now create numNodes-1 nodes and add to end
  Node* prevPtr = headPtr;
  Node* nodePtr = NULL;
  int idx = 1;
  while (idx < numNodes)
  {
    data = (rand() % 20) + 1;
    nodePtr = newNode(data);
    prevPtr->nextPtr = nodePtr;
    prevPtr = nodePtr;
    idx++;
  }

  return headPtr;
}


/** Display List
 * Display a linked list of integer values on standard output.
 *
 * @param list A Node*, the pointer to the head of the
 *   list of interger nodes.
 *
 * @returns void Nothing is return explicitly, but we display
 *    the contents of the list to standard output as a result
 *    of calling this function.
 */
void displayList(Node* list)
{
  while (list != NULL)
  {
    cout << list->data << " -> ";
    list = list->nextPtr;
  }
  cout << "EOL" << endl;
}


/** Average List
 * Average the values in a linked list of integer data.  We
 * are given the head node of a linked list of integers, and w
 * return the floating point value that is the average of the
 * integer valus in the linked list.
 *
 * @param list A Node*, the pointer to the head of the
 *   list of interger nodes.
 *
 * @returns float The average of the values in the list
 *    of integers.
 */
void averageList(Node* list)
{
  float sum = 0.0;
  float count = 0.0;
  while (list != NULL)
  {
    sum += (float)(list->data);
    count += 1.0;
  }

  return (sum / count);
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
  Node* list;

  list = generateRandomList(15);
  cout << "List of 10 integers:" << endl;
  displayList(list);
  
  // return 0 to indicate successful completion
  return 0;
}
