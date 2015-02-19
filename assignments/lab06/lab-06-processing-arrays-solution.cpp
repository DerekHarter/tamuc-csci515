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
#include <fstream>
#include <iomanip>
using namespace std;


// global constants, used to determine array properties
const int NUM_VALUES = 50;
const string INPUT_FILE_NAME = "lab-06-float-array.txt";


/** read in file of floats
 * Read in a file of floating point values into the array provided as
 * input to this function.  Arrays are passed by references, thus by
 * reading the values into the array, the values will be available to the
 * caller of this function.  This function opens up and reads the values
 * from the file, one line at a time.
 *
 * @param values An array of floats, passed by reference.  This function assumes
 *    array has been correctly created of correct size to hold all of the values
 *    from the file we read them in from.
 * @param size Both the size of the array given, and the number of value to read
 *    in from the file.
 * @param filename The name of the file to read our array values from.
 *
 * @returns void No explicit return value, but array values read in are returned in
 *    the values array that is passed to this function.
 */
void readArrayFromFile(float values[], int size, string inputFileName)
{
  ifstream inputFile;
  float value;
  int idx;
  
  // open file, test to ensure it opens properly
  inputFile.open(inputFileName);
  if (!inputFile)
  {
    cerr << "Error: readArrayFromFile: could not open file for reading named: "
	 << inputFileName << endl;
    exit(0);
  }

  // read in the data
  idx = 0;
  while (inputFile >> value)
  {
    values[idx++] = value;
    // be safe, don't read too many values past end of array
    if (idx >= size)
    {
      break;
    }
  }

  // values are returned in the array passed by reference
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
