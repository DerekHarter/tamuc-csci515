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
 * @param deck An array of Card items, large enough to hold a standard 52
 *    card deck, that we will initialize.
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


/** Display Cards in Deck
 * We are given a deck of cards, and a begin and end index of cards to
 * display in the deck.  We display these cards to standard output.
 *
 * @param deck An array of 52 Card items.
 * @param begin The begin index of the cards to display (inclusive)
 * @param end The end index of the cards to display (not included)
 *
 * @returns void But as a side effect we display indicated cards on standard
 *   output.
 */
void displayDeckOfCards(Card deck[], int begin, int end)
{
  for (int idx = begin; idx < end; idx++)
  {
    Card c = deck[idx]; // The current card

    // Determine strings for Face/Suit to display nicely
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
	 << setw(5) << setfill(' ') << faceString
	 << " of "
	 << setfill(' ') << suitString
	 << endl;
  }

}


/** Shuffle Deck of Cards
 * Shuffle an array of Card structures.  This functions
 * assumes a standard deck size of 52 cards, and that the array of cards has
 * already been correctly initilized.  This shuffle works by iterating through
 * every position in the deck, and picking another position to swap with
 * at random.  The result should be a well shuffled deck of cards.
 *
 * @param deck An array of Card items.
 *
 * @returns void But as a side effect the deck of cards is shuffled after return
 */
void shuffleDeckOfCards(Card deck[])
{
  for (int idx = 0; idx < CARDS_IN_DECK; idx++)
  {
    Card c = deck[idx]; // the current card to randomly swap
    Card tmp = c; // Copy the card to a temporary location

    // randomly select another card to swap with
    int anotherIndex = rand() % CARDS_IN_DECK;

    // copy the random card to current location
    deck[idx] = deck[anotherIndex];

    // now copy our temporary copy of the card we are swapping to the
    // random location
    deck[anotherIndex] = tmp;
  }
}


/** Game of High Cards
 * Play a game of high cards between four players.  In this case, we define
 * high card first by suit where HEARTS beats DIAMONDS beats CLUBS beats
 * SPADES.  If 2 or more players have equally high suites, then the value
 * of the card face determines the winner.  This function takes a shuffled
 * deck of standard cards (52 cards in the deck) as its first and only
 * parameter.
 *
 * @param deck An array of Card items, preshuffled.
 *
 * @returns void But as a side effect the deck of cards is shuffled after return
 */
void highestDrawFour(Card deck[])
{
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
  shuffleDeckOfCards(deck);
  displayDeckOfCards(deck, 0, CARDS_IN_DECK);
  //highestDrawFour(deck);
}
