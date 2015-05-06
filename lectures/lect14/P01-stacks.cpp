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

struct Stack
{
  Node* top;
};


/** create empty stack
 * Create an empty stack and return it.
 *
 * @returns stack A Stack*, the pointer to a newly dynamically
 *           allocated stack item.
 */
Stack* createStack()
{
  Stack* stack = new Stack();
  stack->top = NULL;
  return stack;
}


/** push item on stack
 * Given a stack, and an integer item, create a new node and pust the
 * node to the top of the stack.
 *
 * @param stack A Stack* pointing to an existing stack.
 * @param value The value to be pushed onto the stack.
 *
 * @returns stack A Stack*, the pointer to a newly dynamically
 *           allocated stack item.
 */
Stack* createStack()
{
  Stack* stack = new Stack();
  stack->top = NULL;
  return stack;
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
  Stack* s = createStack();

  
  // retun 0 to indicate successful completion
  return 0;
}
