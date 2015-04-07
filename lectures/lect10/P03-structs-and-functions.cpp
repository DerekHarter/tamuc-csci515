/**
 * @author Derek Harter
 * @cwid   123 45 678
 * @class  CSci 515, Spring 2015
 * @ide    Emacs, GCC/G++
 * @date   April 5, 2015
 * @assg   Lecture 10, P03 Using functions with structures
 *
 * @description Examples of passing structures to functions and
 *    returning them from functions.
 */
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
using namespace std;


// Data for a single experimental trial
enum Gender {MALE, FEMALE};

struct Trial
{
  string participantName;
  Gender gender;
  float reactionTime;  // in ms
  int numberOfPresses; // number of times button was pressed
};


/** Display experiment trial
 * Given an experimental trial, format and display its fields/values
 * to standard output.
 *
 * @param trial An experiment Trial record.
 *
 * @returns void, nothing is returned explicitly, but as a side
 *    effect we display the fields of the experimental trial to
 *    standard output.
 */
void displayTrial(Trial trial)
{
  // display the fields
  cout << "      Participant: " << trial.participantName << endl;
  cout << "           Gender: " << (trial.gender == MALE ? "Male" : "Female") << endl;
  cout << "    Reaction Time: " << trial.reactionTime << endl;
  cout << "Number of Presses: " << trial.numberOfPresses << endl;
  cout << endl;
}


/** Conduct experiment trial
 * Conduct a (simulated) experimental trial.  Gather data, and return
 * gathered data record as a Trial structure.
 *
 * @returns Trial The experimental trial data we recorded.
 */
Trial conductTrial()
{
  Trial trial;

  // gather personal information first
  cout << "Enter participant name: ";
  getline(cin, trial.participantName);

  cout << "Enter participant gender (M/F): ";
  string genderString;
  cin >> genderString;
  if (genderString == "M")
  {
    trial.gender = MALE;
  }
  else if (genderString == "F")
  {
    trial.gender = FEMALE;
  }
  else
  {
    cerr << "ERROR: enter either M or F" << endl;
    exit(1);
  }

  // Simulate gathering participant data
  cout << "Press the x button as fast as you can for 1 second... (simulation)" << endl;
  trial.reactionTime = (rand() / RAND_MAX) * 200.0; // 0.0 to 200.0 ms at random
  trial.numberOfPresses = (rand() % 4); // 0 to 3 presses at random

  return trial;
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
  Trial t;

  // initialize the fields
  t.participantName = "Derek Harter";
  t.gender = MALE;
  t.reactionTime = 2.8;
  t.numberOfPresses = 3;
  displayTrial(t);

  // initialize using a list of initializers
  t = {"Susan Smith", FEMALE, 3.7, 2};
  displayTrial(t);

  // call function to gather data and return
  t = conductTrial();
  displayTrial(t);
  
  // return 0 to indicate successfull completion.
  return 0;
}
