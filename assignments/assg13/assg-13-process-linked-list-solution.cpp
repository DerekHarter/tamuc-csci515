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
float averageList(Node* list)
{
  float sum = 0.0;
  float count = 0.0;
  
  while (list != NULL)
  {
    sum += (float)(list->data);
    count += 1.0;
    list = list->nextPtr;
  }

  return (sum / count);
}


/** Concatenate Lists
 * Concatenate two lists to one another.  We are given the head pointer
 * to two different lists.  This function concatenates the second
 * list given to the end of the first.  No value is returned
 * explicitly by this function, but the last item of the first
 * list will be modified to point to the head of the second list,
 * thus effectively concatenating the two lists.
 *
 * @param list1 A Node*, the pointer to the head of the
 *   list of interger nodes.
 * @param list2 A Node*, the pointer to the head of the
 *   other list of interger nodes, to be concatenated to end
 *   of the first list.
 *
 * @returns void Nothing explicit is returned, but as a result
 *    of calling this function, the first list will be modified
 *    to have the second list concatenated on to the end of it.
 */
float concatenateLists(Node* list1, Node* list2)
{
  // find last node in list 1
  Node* nodePtr = list1;
  while (nodePtr->nextPtr != NULL)
  {
    nodePtr = nodePtr->nextPtr;
  }

  // point last node to head of list 2
  nodePtr->nextPtr = list2;
}


/** Reverse a List
 * Given a list of integer items, create a new list with the same number
 * of items.  Cause all of the items in the new list to appear in the reverse
 * order of the items as given in the original list.
 *
 * @param list A Node*, the pointer to the head of the
 *   list of interger nodes we are to reverse
 *
 * @returns Node* A new list of items of the same size as the original
 *    list, but items are arranged in reverse sequential order from the
 *    original list.
 */
Node* reverseList(Node* list)
{
  Node* newList = NULL;
  Node* n = NULL;
  
  while (list != NULL)
  {
    // create new node with copy of current list data item
    n = newNode(list->data);

    // make new node the head of the newList
    n->nextPtr = newList;
    newList = n;
  }

  return newList;
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
  float average;

  // demonstrate using the averageList() function to process list
  list = generateRandomList(10);
  average= averageList(list);
  cout << "List of 10 integers:" << endl;
  displayList(list);
  cout << "Average of list: " << average << endl;
  cout << endl;

  // demonstrate concatentate of two lists
  Node* list1 = generateRandomList(4);
  Node* list2 = generateRandomList(3);
  cout << "List 1:" << endl;
  displayList(list1);
  cout << "List 2:" << endl;
  displayList(list2);
  concatenateLists(list1, list2);
  cout << "After concatenating: " << endl;
  displayList(list1);
  cout << endl;

  // demonstrate revrse list
  Node* list3 = generateRandomList(8);
  Node* r = reverseList(list3);
  cout << "List before reverse:" << endl;
  displayList(list3);
  cout << "List after reverse:" << endl;
  displayList(r);
  cout << endl;
  
  // return 0 to indicate successful completion
  return 0;
}
