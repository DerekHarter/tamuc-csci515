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


/** simulate rolling pairs of dice game
 * Simulate rolling a pair of dice.  We perform a number of simulations of this
 * experiment (provided as input to the function).  We keep track of the number
 * of trials in which the sum of our pairs of dice was either a 7 or an 11.  The
 * ratio of the number of trials that added up to this sum, divided by the total
 * number of trials tried is returned (e.g. the estimated probability of rolling)
 * either a 7 or an 11.
 *
 * @param numTrials An integer value, the number of dice throwing experiments to try.
 *
 * @returns float The ratio of the number of trials that summed up to 7 or 11 among the
 *     total number of trials we ran.
 */
float simulateDiceGame(int numTrials)
{
  int successes = 0;
  int sum;

  for (int trial = 1; trial <= numTrials; trial++)
  {
    // roll a pair of dice
    sum = rollDice() + rollDice();

    // test if the sum was a 7 or an 11
    if ( (sum == 7) || (sum == 11) )
    {
      successes++;
    }
  }

  return float(successes) / float(numTrials);
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
  int seed;
  int numTrials;
  float prob;

  // initialize seed to some known starting point
  cout << "Enter a seed with which to initialize the random number generator: ";
  cin >> seed;
  srand(seed);
  cout << endl;

  // Ask user for number of trials to perform, and do the experiment
  cout << "I will simulate rolling a pair of dice and estimate the probability" << endl;
  cout << "of rolling a 7 or an 11.  Enter the number of trials to run: ";
  cin >> numTrials;
  prob = simulateDiceGame(numTrials);

  cout << endl;
  cout << "I tried " << numTrials << " experiments.  The estimated probability" << endl;
  cout << "of rolling a 7 or an 11 is: " << prob << endl;

  // clean up and return 0 to indicate successful completion
  return 0;
}
