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
  cout << "initDeckOfCards: idx=" << idx << endl;
  for (Suit suit = SPADES; suit <= HEARTS; suit = (Suit)((int)suit + 1) ) 
  {
    for (Face face = DEUCE; face <= ACE; (Face)((int)face + 1) )
    {
      cout << "initDeckOfCards: idx=" << idx << endl;
      deck[idx].suit = suit;
      deck[idx].face = face;
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

  initDeckOfCards(deck);

  for (int idx = 0; idx < CARDS_IN_DECK; idx++)
  {
    Card c = deck[idx];

    // determine the suit, convert to string for display purposes
    string suitString;
    switch (c.suit)
    {
      case SPADES:
	suitString = "Spades";
	break;
      case CLUBS:
	suitString = "Clubs";
	break;
      case DIAMONDS:
	suitString = "Diamonds";
	break;
      case HEARTS:
	suitString = "Hearts";
	break;
    }

    // determine the face value, convert to string
    string faceString;
    switch (c.face)
    {
      case DEUCE:
	faceString = "Deuce";
	break;
      case THREE:
	faceString = "Three";
	break;
      case FOUR:
	faceString = "Four";
	break;
      case FIVE:
	faceString = "Five";
	break;
      case SIX:
	faceString = "Six";
	break;
      case SEVEN:
	faceString = "Seven";
	break;
      case EIGHT:
	faceString = "Eight";
	break;
      case NINE:
	faceString = "Nine";
	break;
      case TEN:
	faceString = "Ten";
	break;
      case JACK:
	faceString = "Jack";
	break;
      case QUEEN:
	faceString = "Queen";
	break;
      case KING:
	faceString = "King";
	break;
      case ACE:
	faceString = "Ace";
	break;
    }

    // display the card
    cout << setw(3) << setfill('0') << idx << ": "
	 << faceString << " of " << suitString << endl;
  }
}
