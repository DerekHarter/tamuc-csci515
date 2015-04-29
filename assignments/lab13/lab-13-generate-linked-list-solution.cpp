/**
 * @author Derek Harter
 * @cwid   123 45 678
 * @class  CSci 515, Spring 2015
 * @ide    Emacs, GCC/G++
 * @date   April 12, 2015
 * @assg   Lab 13
 *
 * @description Create a function to randomly generate a linked list of integer
 *    values.
 */
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


/** Generate Random List
 * Generate and return a linked list of nodes.  The values
 * contained in the nodes will be randomly generated integers
 * in the range from 1 to 20.  We are given a parameter,
 * numNodes, which indicates how many nodes we should create and add
 * to the linked list.  We return a pointer to the head node
 * of the newly dynamically allocated list of integer items.
 *
 * @param nunNodes An integer, the number of nodes we are to
 *   create in our randomly generated list of integer nodes.
 *
 * @returns Node* A pointer to the head node of the linked
 *    list of integers we create.
 */
int posintprint(int* posints)
{
  cout << "{ ";
  while (*posints != -1)
  {
    cout << *posints++;
    if (*posints != -1)
    {
      cout << ", ";
    }
  }
  cout << " }" << endl;
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

  // return 0 to indicate successful completion
  return 0;
}
