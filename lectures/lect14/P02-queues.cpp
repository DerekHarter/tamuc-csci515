/**
 * @author Derek Harter
 * @cwid   123 45 678
 * @class  CSci 515, Spring 2015
 * @ide    Emacs, GCC/G++
 * @date   May 4, 2015
 * @assg   Lecture 14, P02 Queues
 *
 * @description Example queue implementation
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

struct Queue
{
  Node* head;
  Node* tail;
};


/** create empty queue
 * Create an empty queue and return it.
 *
 * @returns queue A Queue*, the pointer to a newly dynamically
 *           allocated queue item.
 */
Queue* createQueue()
{
  Queue* queue = new Queue();
  queue->head = queue->tail = NULL;
  return queue;
}


/** add item to back of queue
 * Enqueue the indicated item to the tail of the given queue.
 *
 * @param queue A Queue* pointing to an existing queue.
 * @param value The value to be added to the end of the queue.
 *
 * @returns void Nothing is returned explicitly, but the
 *    queue will be modified to contain the indicated item as
 *    a new node on the tail of the queue.
 */
void enqueue(Queue* queue, int value)
{
  Node* newItem = new Node();

  // create and initialize the new node to be enqueued on queue
  newItem->data = value;
  newItem->nextPtr = NULL;

  // if queue was empty, set up head and tail to point to new item
  if (queue->head == NULL)
  {
    queue->head = queue->tail = newItem;
  }
  else // queue is not empty, so append to tail
  {
    queue->tail->nextPtr = newItem;
    queue->tail = newItem;
  }
}


/** remove item from front of queue
 * Dequeue the item from the head of the queue.  This function
 * returns an int value, the value at the head of the queue.
 * The queue is modified to remove the head node.  This function
 * will simply exit with an error message if you try to
 * dequeue from an empty queue.
 *
 * @param queue A Queue* pointing to an existing queue.
 *
 * @returns int The value at the had of the queue. As a side
 *    effect the queue will be modified to remove the head
  *   node from the queue.
 */
int dequeue(Queue* queue)
{
  // test for dequeue from empty queue
  if (queue->head == NULL)
  {
    cerr << "dequeue: ERROR: attempt to dequeue from empty queue" << endl;
    exit(1);
  }

  // get the value to return
  int value = queue->head->data;

  // remove the head node from front of queue and deallocate it
  Node* nodeToRemove = queue->head;
  queue->head = queue->head->nextPtr;
  delete(nodeToRemove);
  
  return value;
}


/** test if queue empty
 * Test if the queue is empty or not.  Return true if the stack
 * is empty, and false otherwise.
 *
 * @param stack A Queue* pointing to an existing stack.
 *
 * @returns bool True if stack is currently empty, false
 *    otherwise.
 */
bool isQueueEmpty(Queue* queue)
{
  return (queue->head == NULL);
}


/** print queue
 * Print the values currently on the queue.
 *
 * @param stack A Queue* pointing to an existing stack.
 *
 * @returns void Nothing explicitly returned, but
 *    contents of queue will be displayed on
 *    standard output.
 */
void printQueue(Queue* queue)
{
  // If queue is empty, indicate this
  if (queue->head == NULL)
  {
    cout << "EMPTY" << endl;
  }

  Node* node = queue->head;
  int idx = 1;
  while (node != NULL)
  {
    if ((idx == 1) && (node == queue->tail))
    {
      cout << setw(4) << "HEAD/TAIL";
    }
    else if (idx == 1)
    {
      cout << setw(4) << "HEAD";
    }
    else if (node == queue->tail)
    {
      cout << setw(4) << "TAIL";
    }
    else
    {
      cout << setw(4) << idx;
    }
    cout << ": " << node->data << endl;

    node = node->nextPtr;
    idx++;
  }
  cout << "EOQ (end of queue)" << endl << endl;
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
  Queue* q = createQueue();

  cout << "Queue after creation:" << endl;
  printQueue(q);

  enqueue(q, 5);
  cout << "Queue after enqueuing 1 items:" << endl;
  printQueue(q);

  enqueue(q, 7);
  enqueue(q, 3);
  enqueue(q, 9);
  cout << "Queue after enqueuing 4 items:" << endl;
  printQueue(q);

  int val = dequeue(q);
  cout << "Dequeued value from stack: " << val << endl;
  val = dequeue(q);
  cout << "Dequeued value from stack: " << val << endl;
  cout << "Queue after dequeuing 2 items:" << endl;
  printQueue(q);

  val = dequeue(q);
  cout << "Dequeued value from stack: " << val << endl;
  cout << "Test if queue currently empty: " << (isQueueEmpty(q) ? "True" : "False") << endl;
  cout << "Queue after dequeuing 1 more item:" << endl;
  printQueue(q);

  val = dequeue(q);
  cout << "Dequeued value from stack: " << val << endl;
  cout << "Test if queue currently empty: " << (isQueueEmpty(q) ? "True" : "False") << endl;
  cout << "Queue after dequeuing 1 more item:" << endl;
  printQueue(q);

  val = dequeue(q);
  cout << "Dequeued from empty stack, should not reach this point" << endl;

  // retun 0 to indicate successful completion
  return 0;
}
