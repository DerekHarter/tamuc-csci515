/**
 * @author Derek Harter
 * @cwid   123 45 678
 * @class  CSci 515, Spring 2015
 * @ide    Emacs, GCC/G++
 * @date   February 5, 2015
 * @assg   Lecture 07, P02 Processing 2-D arrays using functions
 *
 * @description Examples of more advanced processing of 2-D arrays
 *   using functions to read from files, and calculated and display
 *   results.
 */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
using namespace std;

// global constant declarations
const int NUM_RECORDINGS = 50; // number of rows/records/experiments in table
const int NUM_DIMENSIONS = 3;  // number of columns/attributes in table
const string experimentFileName = "exp-data.txt";


/** Load Experiment Array
 * Load the 2-D table of experiment recordings from a file.  This
 * functions takes a (passed by reference) 2-D table of experiment
 * recordings.  All of the values in all columns of the table are
 * loaded from the indicated file.  The table is a 2-D array of
 * floating point values, with 3-columns, representing 3 dimensions
 * (x,y,z) of a position of some item recorded during an experiment.
 *
 * @param experimentFileName The name of the file to load data from.
 * @param experimentPositions The 2-D array of experiment positions
 *   we are to initialize.
 * @param size The number of recordings (the number of rows) in the
 *   file we are loading, also the number of rows that the
 *   array can hold that is passed to us.
 *
 * @returns void.  However, since arrays are passed by reference,
 *   as a side effect we load the data from the file into the
 *   passed in array.
 */
void loadExperimentArray(string experimentFileName,
                         float experimentPositions[][NUM_DIMENSIONS],
			 int numRecordings)
{
  ifstream experimentFile(experimentFileName);

  // test we found and opend file successfully
  if (!experimentFile)
  {
    cerr << "ERROR: could not find and open file name: "
	 << experimentFileName << endl;
    exit(1);
  }

  // Read the data from the input file
  for (int record = 0; record < numRecordings; record++)
  {
    for (int dim = 0; dim < NUM_DIMENSIONS; dim++)
    {
      experimentFile >> experimentPositions[record][dim];
    }
  }
}


/** Display Experiment Array
 * Display the 2-D table of experiment recordings.  This functions
 * takes a 2-D table of experiment recordings.  This function does
 * not return a result, but as a side effect it display the
 * values in the experiment array table as a table on standard
 * output
 *
 * @param experimentPositions The 2-D array of experiment positions
 *   we are to initialize.
 * @param size The number of recordings (the number of rows) in the
 *   experiment.
 *
 * @returns void.  However, the values in the experiment array
 *   table are formatted and displayed as a table on standard
 *   output.
 */
void displayExperimentArray(float experimentPositions[][NUM_DIMENSIONS],
			    int numRecordings)
{
  // display a header
  cout << setfill (' ') << setw(4) << left << "Rec "
       << setw(7) << right << "X" << " "
       << setw(7) << right << "Y" << " "
       << setw(7) << right << "Z"
       << endl;

  for (int record = 0; record < numRecordings; record++)
  {
    cout << setw(3) << right << setfill('0') << record << " ";
    for (int dim = 0; dim < NUM_DIMENSIONS; dim++)
    {
      cout << setw(7) << fixed << setprecision(4) << setfill(' ')
	   << experimentPositions[record][dim]
	   << " ";
    }
    cout << endl; // newline at end of the current record
  }
}


/** Calculate Trial Distances
 * Calculate the distances between successive trials.  We are
 * given the 2-D table of experimental positions, and 
 * a 1-D array that will hold the result of calculating the
 * distances between subsequent trials.
 *
 * @param experimentPositions The 2-D array of experiment positions
 *   we are to initialize.
 * @param size The number of recordings (the number of rows) in the
 *   experiment.
 * @param distances An array of size-1 float elements, will hold the
 *   results of calculating the distances between subsequent positions
 *   in the experimentPositions data.
 *
 * @returns void.  However, we return the result of calculating the
 *   distances of subsequent trials in the experimenta positions in
 *   the distances array.
 */
void calculateTrialDistances(float experimentPositions[][NUM_DIMENSIONS],
			     int numRecordings,
			     float distances[])
{
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

  // 2-D arrays in C are organized in memory using row ordering
  // Compiler does not need the number of rows, put it needs
  // to know/specify the number of columns.
  loadExperimentArray(experimentFileName, experimentPositions, NUM_RECORDINGS);
  displayExperimentArray(experimentPositions, NUM_RECORDINGS);

  // Process 2-D array, determine distance traveled between subsequent recordings
  float distances[NUM_RECORDINGS-1];
  calculateTrialDistances(experimentPositions, NUM_RECORDINGS, distances);
  //displayExperimentDistances(distances, NUM_RECORDINGS-1);
  
}
