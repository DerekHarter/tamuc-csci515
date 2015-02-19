/**
 * @author Derek Harter
 * @cwid   123 45 678
 * @class  CSci 515, Spring 2015
 * @ide    Gnu C/C++, Emacs
 * @date   February 19, 2015
 * @assg   Lab 06
 *
 * @description Example of processing arrays.  We write functions to display selected
 *    portions of an array, and to determine the average of the values in an
 *    array.  This program also contains an example of a function that reads in the
 *    values from a file into an array of floats for processing by the other functions.
 */
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;


// global constants, used to determine array properties
const int NUM_ITEMS_IN_FILE = 50;
const string INPUT_FILE = "lab-06-float-array.txt";


/** roll a dice
 * Roll a single dice.  Return a random number in the range [1, 6] (inclusive)
 *
 * @returns int The randomly rolled dice, an integer in the range [1, 6]
 */
int rollDice()
{
  return (rand() % 6) + 1;
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
  float values[];
}
