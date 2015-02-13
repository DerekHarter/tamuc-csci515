/**
 * @author Derek Harter
 * @cwid   123 45 678
 * @class  CSci 515, Spring 2015
 * @ide    Emacs, GCC/G++
 * @date   February 5, 2015
 * @assg   Lecture 04, P02 User Defined Functions
 *
 * @description Example of using the c standard library random number generator functions.
 */
#include <iostream>
#include <cstdlib>
using namespace std;


// global declarations
enum Coin {HEADS, TAILS};


/** toss a coin
 * Perform a random (fair) coin toss.  Use enumerated type to define our coin toss result.
 * This function returns either HEADS or TAILS randomly, with equal probability.
 *
 * @returns Coin Either HEADS or TAILS at random simulating a random coin toss
 */
Coin tossCoin()
{
  // use rand to generate a random number, use mod to change range into 2 values, 0 or 1
  if (rand() % 2 == 0)
  {
    return HEADS;
  }
  else
  {
    return TAILS;
  }
}


/** random number in range
 * Generate a random number within a range.  We take two integer parameters as input
 * a and b, the beginning and end of the range.  We will generate a random number
 * and scale it to be within the indicated range, and return it.  This function
 * returns integer values with an equal probability of returning any value within
 * the range.  This function is inclusive, thus the a and b begin and end of range
 * can also be returned by this function.
 *
 * @param a an integer, the beginning of the range within which to generate a random value.
 * @param b an integer, the end of the range within which to generate a random value.
 * 
 * @returns int An integer value within range a to b, e.g. a <= return <= b
 */
int randomRange(int a, int b)
{
  int val;

  // first generate a value in range 0 to RAND_MAX
  val = rand();

  // now we scale the value
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
  int seed;

  // setting the pseudo-random generator seed
  cout << "Enter a seed value to seed pseudo-random generator with: ";
  cin >> seed;
  srand(seed);

  cout << "First 10 integers for this seed: " << endl;
  for (int i=0; i < 10; i++)
  {
    cout << rand() << endl;
  }
  cout << "RAND_MAX is " << RAND_MAX << endl;

  // flipping a coin
  // lets flip 10 coins at random and count up the results
  int numHeads;
  int numTails;

  numHeads = numTails = 0;
  for (int i=0; i < 10; i++)
  {
    if (tossCoin() == HEADS)
    {
      numHeads++;
    }
    else
    {
      numTails++;
    }
  }
  cout << "After 10 coin tosses, we got " << numHeads << " Heads and " << numTails << " tails." << endl;

  // Example of function to return random number in range from a to b
}
