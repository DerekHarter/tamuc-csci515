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


/** Higher Card
 * Compare two Card items, named card1 and card2, to determine which
 * is the higher card.  We use the rule that first sorts cards by
 * their suit where HEARTS beats DIAMONDS beats CLUBS beats
 * SPADES.  If the two cards have the same suite, then the value
 * of the card face determines the winner.  This function returns
 * a boolean result of True if card1 is the higher card, and False
 * if it is card2.
 *
 * @param card1 A Card item
 * @param card2 Another Card to be compared with the first
 *
 * @returns bool true if card1 is higher than card2, false otherwise
 */
bool isCardHigher(Card card1, Card card2)
{
  // if the suit of card1 beats the suit of card2, it is higher
  if (card1.suit > card2.suit)
  {
    return true;
  }
  // if the suit is smaller, then it is lower
  else if (card1.suit < card2.suit)
  {
    return false;
  }
  // otherwise suits are equal, so simply return face comparison
  else if (card1.suit == card2.suit)
  {
    return card1.face > card2.face;
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
 * @returns void But as a side effect we display the winner of the highest card
 *    draws among the 4 players.
 */
void highestDrawFour(Card deck[])
{
  const int NUM_PLAYERS = 4; // we hard code to play 4 players, but we could change this to a parameter
  int winningPlayer = 0;  // Keep track of the winning player
  Card winningCard = deck[winningPlayer]; // start by assuming player 0 is winner

  // Test players 1 up to number of players, to find one with a better card
  for (int otherPlayer = 1; otherPlayer < NUM_PLAYERS; otherPlayer++)
  {
    // test if the card is higher than the current winner
    if ( isCardHigher(deck[otherPlayer], winningCard) )
    {
      winningCard = deck[otherPlayer];
      winningPlayer = otherPlayer;
    }
  }

  cout << "highestDrawFour(): winning player: " << winningPlayer << endl;
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
  srand(time(0)); // always shuffle with different random shuffle
  shuffleDeckOfCards(deck);
  displayDeckOfCards(deck, 0, 4);
  highestDrawFour(deck);
}
