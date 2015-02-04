/**
 * @author Derek Harter
 * @cwid   123 45 678
 * @class  CSci 515, Spring 2015
 * @ide    Gnu C/C++, Emacs 24
 * @date   January 30, 2015
 * @assg   Assg 03
 *
 * @description An example solution for the Assg 03.  We use 2 sets of
 *     3D coordinates, x,y,z and x_prev, y_prev, z_prev.  The values
 *     for current trial are always read into x,y,z.  Whenever we
 *     successfully calculate a distance, we copy the current values
 *     into x_prev, y_prev, z_prev, so that they will be available for
 *     the next occurrence of the trial class we are filtering on.  We
 *     use a specific flag variable, firstTrial, to skip over
 *     calculating distance for the first trial we encounter, since at
 *     that point we have no previous position with which to calculate
 *     a distance against.
 */
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <math.h>
using namespace std;


/** main entry point
 * The main entry point for this program.  Execution
 * of this program will beigin with this function.
 *
 * @returns An int value.  By default, if we don't specify a return or
 *           exit value, 0 is returned to indicate successful program
 *           completion.  A non-zero value indicates an error or
 *           problem with execution.
 */
int main()
{
  // files
  string inputFileName = "assg-03-data-in.dsv";
  ifstream inputFile(inputFileName.c_str());
  string outputFileName = "assg-03-data-out.dsv";
  ofstream outputFile(outputFileName.c_str());

  // variables for file processing
  string filterClass;
  string trialClass;
  int trial;
  float x_prev, y_prev, z_prev;  // hold previous values of position
  float x, y, z; // will hold current values of position
  float distance;
  bool firstTrial = true; // use a flag to handle first item, before
			  // we have 2 items to calc distance with

  // test we found and opened file successfully
  if (!inputFile)
  {
    cout << "ERROR: could not find input file named: " << inputFileName << endl;
    exit(1);
  }
  if (!outputFile)
  {
    cout << "ERROR: could not create output file named: "
	 << outputFileName << endl;
    exit(1);
  }

  // first read the filter information, and skip over the header
  inputFile >> filterClass;
  string headerLine;
  getline(inputFile, headerLine);  // skips past newline?
  getline(inputFile, headerLine);  // skips the next line, which has header

  // now process all of the lines of data
  // current values of position are put into x, y and z
  while (inputFile >> trial >> x >> y >> z >> trialClass)
  {
    // filter items by their class, only process items of the correct class
    if (trialClass == filterClass)
    {
      // if this is our first time in, then we can't calculate distance yet
      if (firstTrial)
      {
	firstTrial = false;
      }
      else // we need to calculate distance between current and prev, and output results
      {
	distance = sqrt( pow(x - x_prev, 2.0) + pow(y - y_prev, 2.0) + pow(z - z_prev, 2.0) ); 
	outputFile << setfill('0') << setw(5) << trial
		   << setfill(' ') << setw(10) << fixed << setprecision(5) << distance << endl;
      }

      // keep track of these values for next distance calculation
      x_prev = x;
      y_prev = y;
      z_prev = z;
    }
  }

  // return 0 to indicate successful completion
  inputFile.close();
  outputFile.close();
  return 0;
}
