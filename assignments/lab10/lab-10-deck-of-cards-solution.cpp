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


/** Initialize Deck of Cards
 * Initialize an array of Card structures.  This initializes
 * assumes a standard deck size of 52 cards, and initialzes deck with all
 * 52 combinations of 4 suits with 13 face values.
 *
 * @returns void But as a side effect the deck of cards is initialized.
 */
void initDeckOfCards(Card deck[])
{
  int idx;

  // I will use the fact that by default the values in enum are ints from 0 to last
  idx = 0;
  for (int suit = SPADES; suit <= HEARTS; suit++)
  {
    for (int face = DEUCE; face <= ACE; face++)
    {
      deck[idx].suit = (Suit)suit;
      deck[idx].face = (Face)face;
      idx++;
    }
  }
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
  Card deck[CARDS_IN_DECK];

  initDeckOfCards();
  
}
