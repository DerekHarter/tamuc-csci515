/**
 * @author Derek Harter
 * @cwid   123 45 678
 * @class  CSci 515, Spring 2015
 * @ide    Emacs, GCC/G++
 * @date   April 5, 2015
 * @assg   Lecture 10, P01 Defining structs
 *
 * @description Declare a structure data type to hold experiment trial data.
 *    Show example of initializing the structure.
 */
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;


// Data for a single experimental trial
struct Trial
{
  string participantName;
  string gender;
  float reactionTime;  // in ms
  int numberOfPresses; // number of times button was pressed
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
  Trial t;
  
  // return 0 to indicate successfull completion.
  return 0;
}
