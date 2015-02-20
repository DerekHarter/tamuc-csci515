/**
 * @author Derek Harter
 * @cwid   123 45 678
 * @class  CSci 515, Spring 2015
 * @ide    Gnu C/C++, Emacs
 * @date   February 19, 2015
 * @assg   Assg 06
 *
 * @description Examples of performing calculations on and with arrays.  All functions take an
 *    array (and the size of the array) as inputs.  The functions perform a calculation on the
 *    values in the array, and return the result as a single floating point result value.
 */
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;


// global constants, used to determine array properties
const int NUM_VALUES = 100;
const string INPUT_FILE_NAME = "assg-06-float-array.txt";


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
    exit(1);
  }

  // read in the data
  idx = 0;
  while (inputFile >> value)
  {
    values[idx] = value;

    // increment index for next read
    // be safe, if array is now full, stop reading
    idx++;
    if (idx >= size)
    {
      break;
    }
  }

  // values are returned in the array passed by reference
}


/** find minimum value
 * Find the minimum value in an array of floats.  We are given the array
 * and the size of the array as input.  We return the minimum value as the
 * result of this function.
 *
 * @param values An array of floats, passed by reference.
 * @param size The size of the array we are searching.
 *
 * @returns float The minimum value in the array
 */
float findMinimumValue(float values[], int size)
{
  float minimum;

  // We initialize minimum to the first value, then search values 1..size-1 for smaller ones
  minimum = values[0];
  for (int idx = 1; idx < size; idx++)
  {
    if (values[idx] < minimum)
    {
      minimum = values[idx];
    }
  }

  return minimum;
}


/** find maximum value
 * Find the maximum value in an array of floats.  We are given the array
 * and the size of the array as input.  We return the maximum value as the
 * result of this function.
 *
 * @param values An array of floats, passed by reference.
 * @param size The size of the array we are searching.
 *
 * @returns float The maximum value in the array
 */
float findMaximumValue(float values[], int size)
{
  float maximum;

  // We initialize maximum to the first value, then search values 1..size-1 for larger ones
  maximum = values[0];
  for (int idx = 1; idx < size; idx++)
  {
    if (values[idx] > maximum)
    {
      maximum = values[idx];
    }
  }

  return maximum;
}


/** find sum
 * Find the sum of all of the values in an array of floats.  We are
 * given the array and the size of the array as input.  We return the
 * sum of all of the value as the result of this function.
 *
 * @param values An array of floats, passed by reference.
 * @param size The size of the array we are searching.
 *
 * @returns float The sum of the values in the array
 */
float findSum(float values[], int size)
{
  float sum;

  // Initialily sum is 0.0, then we add up all of the values in the array
  // using a running sum
  sum = 0.0
  for (int idx = 0; idx < size; idx++)
  {
    sum += values[ids];
  }

  return sum;
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
  float values[NUM_VALUES];

  // load the values from a file into our array
  readArrayFromFile(values, NUM_VALUES, INPUT_FILE_NAME);

  // display the results from processing our array of values
  cout << "Minimum: " << setw(12) << fixed << setprecision(8) << findMinimumValue(values, NUM_VALUES) << endl;
  cout << "Maximum: " << setw(12) << fixed << setprecision(8) << findMaximumValue(values, NUM_VALUES) << endl;
  cout << "Sum:     " << setw(12) << fixed << setprecision(8) << findMaximumValue(values, NUM_VALUES) << endl;
  
  //  Return 0 to indicate program terminated successfully
  return 0;
}
