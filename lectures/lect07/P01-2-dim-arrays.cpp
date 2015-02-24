/**
 * @author Derek Harter
 * @cwid   123 45 678
 * @class  CSci 515, Spring 2015
 * @ide    Emacs, GCC/G++
 * @date   February 5, 2015
 * @assg   Lecture 07, P02 Intro to 2-D arrays
 *
 * @description Examples of declaring and initializing a 2-D array
 */
#include <iostream>
using namespace std;

// global constant declarations
const int NUM_RECORDINGS = 5; // number of rows/records/experiments in table
const int NUM_DIMENSIONS = 3; // number of columns/attributes in table


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
  // Each experiment records a 3-dimensional position of a particle
  // for multiple recordings during the experiment
  float experimentPositions[NUM_RECORDINGS][NUM_DIMENSIONS];

  // We initialize a 2-D array using 2 (nested) loops
  for (int record = 0; record < NUM_RECORDINGS; record++)
  {
    for (int dim = 0; dim < NUM_DIMENSIONS; dim++)
    {
      experimentPositions[record][dim] = 0.0;
    }
  }

  // We access/display the values in a 2-D array again using
  // a nested loop
  for (int record = 0; record < NUM_RECORDINGS; record++)
  {
    cout << "Rec " << setw(3) << setfill('0') << record << ":"
    for (int dim = 0; dim < NUM_DIMENSIONS; dim++)
    {
	   << setw(6) << fixed << setprecision(4) <<
      experimentPositions[record][dim] = 0.0;
    }
  }

  // 2-D arrays in C are organized in memory using row ordering
  // Compiler does not need the number of rows, put it needs
  // to know/specify the number of columns.
  initExperimentArray(experimentPositions, NUM_RECORDINGS);
  displayExperimentArray(experimentPositions, NUM_RECORDINGS);
}
