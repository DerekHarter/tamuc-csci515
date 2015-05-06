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
 * Given a stack, and an integer item, create a new node and push the
 * node to the top of the stack.
 *
 * @param stack A Stack* pointing to an existing stack.
 * @param value The value to be pushed onto the stack.
 *
 * @returns void Nothing is returned explicitly, but the
 *    stack will be modified to contain the indicated item on the top
 *    of the stack.
 */
void push(Stack* stack, int value)
{
  Node* newItem = new Node();

  // create and initialize the new node to be pushed on stack
  newItem->data = value;

  // push the new node to the top of the stack
  newItem->next = stack->top;
  stack->top = newItem;
}


/** pop item from stack
 * Pop and remove the top item from the stack.  This
 * function returns an int value, the value of the top
 * item on the stack.  This function will simply exit
 * if you try and pop from an empty stack.  The stack
 * is modified to remove the top node from the stack.
 *
 * @param stack A Stack* pointing to an existing stack.
 *
 * @returns int The value of the top node on the stack.
 *    As a side effect the stack will be modified to
 *    remove the top node from the stack.
 */
int pop(Stack* stack)
{
  // test for pop from empty stack
  if (stack->top == NULL)
  {
    cerr << "pop: ERROR: attempt to pop from empty stack" << endl;
    exit(1);
  }

  // get the value to return
  int value = stack->top->data;

  // remove the top node from the stack, and deallocate it
  Node* nodeToRemove = stack->top;
  stack->top = stack->top->nextPtr;
  delete(nodeToRemove);

  return value;
}


/** print stack
 * Print the values currently on the stack.
 *
 * @param stack A Stack* pointing to an existing stack.
 *
 * @returns void Nothing explicitly returned, but
 *    contents of stack will be displayed on
 *    standard output.
 */
void printStack(Stack* stack)
{
  // If stack is empty, indicate this
  if (stack->top == NULL)
  {
    cout << "EMPTY" << endl;
  }

  Node* node = stack->top;
  int idx = 1;
  while (node != NULL)
  {
    cout << setw(3) << idx
	 << ": "
	 << node->data
	 << endl;
  }
  cout << "EOS (end of stack)" << endl;
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
