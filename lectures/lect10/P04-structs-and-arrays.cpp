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


/** Load Iris Flower data
 * Load the iris flower data from file.  File is a comma separated
 * delimiter formatted file of recorded flower information.  We load
 * the data into the provided array of IrisSample records.  This array
 * is passed by reference, thus the loaded data is accessible to the
 * caller of this function.
 *
 * @param irisSamples An array of IrisSample records, large enough to
 *   hold all of the data we will attempt to read in from the file.
 *
 * @returns int We return the number of samples loaded into the array.
 */
int loadIrisData(IrisSample irisSamples[])
{
  ifstream inputDataFile;

  // open file for loading
  inputDataFile.open(irisDataFileName);
  if (!inputDataFile)
  {
    cerr << "ERROR: loadIrisData(): could not find file for loading: " << irisDataFileName << endl;
    exit(1);
  }

  // if file was opened successfully, read in data a line at a times
  float sepalLength, sepalWidth, petalLength, petalWidth;
  string speciesString;
  int idx = 0;
  while (inputDataFile >> sepalLength >> sepalWidth >> petalLength >> petalWidth >> speciesString)
  {
    // process and record flower data
    irisSamples[idx].sepalLength = sepalLength;
    irisSamples[idx].sepalWidth = sepalWidth;
    irisSamples[idx].petalLength = petalLength;
    irisSamples[idx].petalWidth = petalWidth;

    // convert species string to correct type
    if (speciesString == "Iris-setosa")
    {
      irisSamples[idx].species = SETOSA;
    }
    else if (speciesString == "Iris-versicolor")
    {
      irisSamples[idx].species = VERSICOLOR;
    }
    else if (speciesString == "Iris-virginica")
    {
      irisSamples[idx].species = VIRGINICA;
    }
    else
    {
      cerr << "ERROR: loadIrisData(): unknown flower species type: " << speciesString << endl;
      exit(1);
    }

    // increment index for next record read, test if we exceed maximum records
    idx++;
    if (idx > MAX_SAMPLES)
    {
      cerr << "ERROR: loadIrisData(): exceeded maximum records" << endl;
      exit(1);
    }
  }

  return idx;
}


/** Display Iris Samples
 * Given an array of IrisSample records, display the data for the
 * indicated records on standard output.
 *
 * @param irisSamples An array of loaded IrisSample records.
 * @param begin An int, the beginning index of the data to display
 * @param end An int, the ending index of the data we are to display
 *    (noninclusive).
 *
 * @returns void, nothing is returned explicitly, but as a side effect
 *    we display the indicated records from the samples to standard
 *    output.
 */
void displayIrisSamples(IrisSample irisSamples[], int begin, int end)
{
  // display a header
  cout << setw(3) << "IDX"
       << setw(11) << "Species"
       << setw(5) << "SepL"
       << setw(5) << "SepW"
       << setw(5) << "PetL"
       << setw(5) << "PetW"
       << endl;
  
  // display all of the indicated records
  for (int idx = begin; idx < end; idx++)
  {
    IrisSample s = irisSamples[idx];
    string speciesString;

    // convert type to string for display
    if (s.species == SETOSA)
    {
      speciesString = "Setosa";
    }
    else if (s.species == VERSICOLOR)
    {
      speciesString = "Versicolor";
    }
    else if (s.species == VIRGINICA)
    {
      speciesString = "Virginica";
    }
    else
    {
      speciesString = "UNKNOWN/ERROR";
    }

    // display the record
    cout << setw(3)  << setfill('0') << idx
         << setw(11) << setfill(' ') << right << speciesString 
	 << setw(5)  << setfill(' ') << setprecision(2) << fixed << showpoint << s.sepalLength
	 << setw(5)  << setfill(' ') << setprecision(2) << fixed << showpoint << s.sepalWidth
	 << setw(5)  << setfill(' ') << setprecision(2) << fixed << showpoint << s.petalLength
	 << setw(5)  << setfill(' ') << setprecision(2) << fixed << showpoint << s.petalWidth
	 << endl;
  }
}


/** Calculate avg petal length of species
 * Calculate the average petal length for a particular species of flower.
 * We are given a table of IrisSample records containing the data, and
 * the number of records in the table.  The data contains measurements from
 * several species of flower.  We are also given a particular
 * species type as a parameter.  We calculate the average petal length
 * only for the flower of the given species in the data table.
 *
 * @param irisSamples An array of loaded IrisSample records.
 * @param numSamples int The total number of records in the data table
 * @param species IrisSpecies The species we are to extract data for
 *    and calculate averages of petal lengths.
 *
 * @returns float The average petal length of the flower in the data
 *    table of the indicated species.
 */
void displayIrisSamples(IrisSample irisSamples[], int begin, int end)
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
  IrisSample irisSamples[MAX_SAMPLES];
  int numSamples;
  
  // load the iris flower data from file
  numSamples = loadIrisData(irisSamples);
  cout << "We successfully loaded " << numSamples << " samples from data file" << endl;
  
  // display first 10 samples, to ensure we loaded properly
  displayIrisSamples(irisSamples, 45, 55);

  float avgLength;
  // calculate average petal length for each species and display
  //avgLength = calculateAveragePetalLengthForSpecies(irisSamples, MAX_SAMPLES)
  
  // return 0 to indicate successfull completion.
  return 0;
}

