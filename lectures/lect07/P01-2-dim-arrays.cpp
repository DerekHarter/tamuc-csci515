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
#include <iomanip>
using namespace std;

// global constant declarations
const int NUM_RECORDINGS = 5; // number of rows/records/experiments in table
const int NUM_DIMENSIONS = 3; // number of columns/attributes in table


/** Initialize Experiment Table
 * Initialize the 2-D table of experiment recordings.
 * This functions takes a (passed by reference) 2-D table
 * of experiment recordings.  All of the values in all columns
 * of the table are initialized to 0.0.  The table is a 2-D array
 * of floating point values, with 3-columns, representing 3 dimensions
 * (x,y,z) of a position of some item recorded during an experiment.
 *
 * @param experimentPositions The 2-D array of experiment positions
 *   we are to initialize.
 * @param size The number of recordings (the number of rows) in the
 *   experiment.
 *
 * @returns void.  However, since arrays are passed by reference,
 *   as a side effect we initialize the experimentPositions table
 *   of values to 0.0 and return to the caller.
 */
int initExperimentArray(float experimentPositions[][NUM_DIMENSIONS],
			int numRecordings)
{
  for (int record = 0; record < numRecordings; record++)
  {
    for (int dim = 0; dim < NUM_DIMENSIONS; dim++)
    {
      experimentPositions[record][dim] = 0.0;
    }
  }
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
    cout << "Rec " << setw(3) << setfill('0') << record << ": ";
    for (int dim = 0; dim < NUM_DIMENSIONS; dim++)
    {
      cout << setw(6) << fixed << setprecision(4)
	   << experimentPositions[record][dim]
	   << " ";
    }
    cout << endl; // newline at end of the current record
  }
  cout << endl;
  
  // 2-D arrays in C are organized in memory using row ordering
  // Compiler does not need the number of rows, put it needs
  // to know/specify the number of columns.
  initExperimentArray(experimentPositions, NUM_RECORDINGS);
  //displayExperimentArray(experimentPositions, NUM_RECORDINGS);
}
