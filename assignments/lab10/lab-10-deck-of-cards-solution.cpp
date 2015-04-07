/**
 * @author Derek Harter
 * @cwid   123 45 678
 * @class  CSci 515, Spring 2015
 * @ide    Emacs, GCC/G++
 * @date   March 25, 2015
 * @assg   Lab 10
 *
 * @description Simulate creation of a deck of cards.  Demonstrate user
 *    defined data types for a Card, and create an array of such Card types.
 */
#include <iostream>
#include <iomanip>
using namespace std;


// User defined Card type
const int CARDS_IN_DECK = 52;
enum Suit {SPADES, CLUBS, DIAMONDS, HEARTS};
enum Face {DEUCE, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE};
struct Card
{
  Suit suit;
  Face face;
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
  Card deck[CARDS_IN_DECK];
}
