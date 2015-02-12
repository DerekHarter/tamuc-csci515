/**
 * @author Derek Harter
 * @cwid   123 45 678
 * @class  CSci 515, Spring 2015
 * @ide    Gnu C/C++, Emacs
 * @date   February 5, 2015
 * @assg   Lab 05
 *
 * @description Simulate a game of dice.  Roll pairs of dice and count up
 *    the number of rolls where the sum is a 7 or an 11.  Use this to
 *    approximate the expected probability of rolling a 7 or an 11.
 */
#include <iostream>
#include <cstdlib>
using namespace std;


/** roll a dice
 * Roll a single dice.  Return a random number in the range [1, 6] (inclusive)
 *
 * @returns int The randomly rolled dice, an integer in the range [1, 6]
 */
int rollDice()
{
  return (rand() % 6) + 1;
}


/** find perfect numbers
 * Find all perfect numbers in the range from 1 to n.  n is passed in as a parameter
 * determining how far we should search.  We display the results on standard ouput
 * of the perfect numbers we find.
 *
 * @param int n The maximum number we are to search up to, we will search through
 *    all values from 1 to n
 *
 * @returns void Output is displayed on standard output.
 */
void findPerfectNumbers(int n)
{
}


/** main entry point
 * The main entry point for this program.  Execution
 * of this program will beigin with this function.
 *
 * @returns An int value.  By default, if we don't specify a return or
 *           exit value, 0 is returned to indicate successful program
 *           completion.  A non-zero value indicates an error or
 *           problem with execution.  Summary information is calculated
 *           while processing the individual lines of input.
 */
int main()
{
  // initialize seed to some known starting point
  srand(42);

  // test the rollDice() function
  for (int i=0; i<10; i++)
  {
    cout << "Rolling the dice, rolled a: " << rollDice() << endl;
  }

  // clean up and return 0 to indicate successful completion
  return 0;
}
