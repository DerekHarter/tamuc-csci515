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
  newItem->nextPtr = stack->top;
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


/** test if stack empty
 * Test if the stack is empty or not.  Return true if
 * the stack is empty, and false otherwise.
 *
 * @param stack A Stack* pointing to an existing stack.
 *
 * @returns bool True if stack is currently empty,
 *    false otherwise.
 */
int isStackEmpty(Stack* stack)
{
  return (stack->top == NULL);
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
    if (idx == 1)
    {
      cout << setw(3) << "TOP";
    }
    else
    {
      cout << setw(3) << idx;
    }
    cout << ": " << node->data << endl;

    node = node->nextPtr;
    idx++;
  }
  cout << "EOS (end of stack)" << endl << endl;
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

  cout << "Stack after creation:" << endl;
  printStack(s);

  push(s, 5);
  push(s, 3);
  push(s, 7);
  cout << "Stack after pushing 3 items:" << endl;
  printStack(s);

  int val = pop(s); 
  cout << "Poped value from stack: " << val << endl;
  val = pop(s);
  cout << "Poped value from stack: " << val << endl;
  cout << "Test if stack currently empty: " << (isStackEmpty(s) ? "True" : "False") << endl;
  cout << "Stack after 2 pops: " << endl;
  printStack(s);

  val = pop(s);
  cout << "Poped value from stack: " << val << endl;
  cout << "Test if stack currently empty: " << (isStackEmpty(s) ? "True" : "False") << endl;
  cout << "Stack after 3 pops: " << endl;
  printStack(s);

  val = pop(s);
  cout << "Poped from empty stack, should not reach this point" << endl;

  // retun 0 to indicate successful completion
  return 0;
}
