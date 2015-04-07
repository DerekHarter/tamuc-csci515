/**
 * @author Derek Harter
 * @cwid   123 45 678
 * @class  CSci 515, Spring 2015
 * @ide    Emacs, GCC/G++
 * @date   April 5, 2015
 * @assg   Lecture 10, P02 User Defined Types
 *
 * @description More example and discussion of what it means to define
 *    new variable types for the language.
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

  // initialize the fields
  t.participantName = "Derek Harter";
  t.gender = "Male";
  t.reactionTime = 2.8;
  t.numberOfPresses = 3;

  // access the fields
  cout << "      Participant: " << t.participantName << endl;
  cout << "           Gender: " << t.gender << endl;
  cout << "    Reaction Time: " << t.reactionTime << endl;
  cout << "Number of Presses: " << t.numberOfPresses << endl;
  cout << endl;

  // initialize using a list of initializers
  t = {"Susan Smith", "Female", 3.7, 2};
  cout << "      Participant: " << t.participantName << endl;
  cout << "           Gender: " << t.gender << endl;
  cout << "    Reaction Time: " << t.reactionTime << endl;
  cout << "Number of Presses: " << t.numberOfPresses << endl;
  cout << endl;

  // return 0 to indicate successfull completion.
  return 0;
}
