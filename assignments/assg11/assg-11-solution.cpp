/**
 * @author Derek Harter
 * @cwid   123 45 678
 * @class  CSci 515, Spring 2015
 * @ide    Emacs, GCC/G++
 * @date   March 25, 2015
 * @assg   Assignment 10
 *
 * @description Play a little card game.  Simulate creation of a deck of
 *    cards, with functions to display and shuffle the cards.  Play a game
 *    where 4 players draw top cards, and the highest suit/face is the
 *    winner.
 */
#include <iostream>
#include <iomanip>
using namespace std;


// A structure to hold an Integer
// and a pointer to some other item.
struct IntegerItem
{
  int value;
  IntegerItem* nextPtr;
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
  IntegerItem a;
  IntgerItem b;
  IntegerItem c;
  IntegerItem d;

  a.value = 5;
  b.value = 7;
  c.value = 10;
  d.value = 15;

  a.nextPtr = &b;
  b.nextPtr = &c;
  c.nextPtr = &d;
  d.nextPtr = &a;

  IntegerItem* aPtr = &a;
  IntegerItem* cPtr = &c;

  cout << "Two hops on chain away from a: " << aPtr->nextPtr->nextPtr << endl;
  cout << "Three hops on chain away from c: " << cPtr->nextPtr->nextPtr->nextPtr << endl;
  cout << "Four hops on chain away from a: " << aPtr->nextPtr->nextPtr->nextPtr->nextPtr << endl;
}
