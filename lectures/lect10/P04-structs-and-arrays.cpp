/**
 * @author Derek Harter
 * @cwid   123 45 678
 * @class  CSci 515, Spring 2015
 * @ide    Emacs, GCC/G++
 * @date   April 5, 2015
 * @assg   Lecture 10, P04 Arrays of structures
 *
 * @description Examples of declaring arrays of structures and using
 *    them as basic tables of data for processing.
 */
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <fstream>
using namespace std;


// Data for a single experimental trial
enum IrisSpecies {SETOSA, VERSICOLOR, VIRGINICA};

struct IrisSample
{
  float sepalLength; // cm
  float sepalWidth;  // cm
  float petalLength; // cm
  float petalWidth;  // cm
  IrisSpecies species;
};

// At maximum we will load and process 150 samples of our data
const int MAX_SAMPLES = 150;
const string irisDataFileName = "iris.csv";


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
void loadIrisData(IrisSample samples)
{
  string speciesString;
  ifstream inputDataFile;

  // open file for loading
  inputDataFile.open(irisDataFileName);
  if (!inputDataFile)
  {
    cerr << "ERROR: could not find file for loading: " << irisDataFileName << endl;
    exit(1);
  }

  // if file was opened successfully, read in data a line at a times
  //while ()
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
  Iris irisSamples[MAX_SAMPLES];

  // load the iris flower data from file
  loadIrisData(irisSamples);

  // display first 10 samples, to ensure we loaded properly
  //displayIrisSamples(irisSamples, 0, 10);

  // return 0 to indicate successfull completion.
  return 0;
}

