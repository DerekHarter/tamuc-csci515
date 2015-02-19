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


/** display array values
 * Display values in an array in a given range.  We indicate the
 * indices and format the values to give a uniform, nice appearance
 * on standard output.
 *
 * @param values An array of floats, passed by reference.
 * @param beginRange An integer parameter, the first index of range of values
 *    to be printed.
 * @param endRange An integer parameter, the last index of range of values to be
 *    printed.
 *
 * @returns void Results printed to standard output as a side effect.
 */
void displayArrayValues(float values[], int beginRange, int endRange)
{
  for (int idx = beginRange; idx <= endRange; idx++)
  {
    cout << "value[" << setw(3) << idx << "] "
	 << setw(12) << setprecision(8) << values[idx] << endl;
  }
}


/** calculate array average
 * Calculate the average of the values in an array.  We are given the
 * array and its size.  We compute the average of all values, and return
 * this value as our result.
 *
 * @param values An array of floats, passed by reference.
 * @param size The size of the array.
 *
 * @returns float The average of the values in the array
 */
void calculateArrayAverage(float values[], int size)
{
  float sum;

  // find the sum of all of the values in array
  sum = 0.0;
  for (int idx = 0; idx < size; idx++)
  {
    sum += values[idx];
  }

  // calculate and return the average
  return sum / (float) size;
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
  int beginRange;
  int endRange;

  // load the values from a file into our array
  readArrayFromFile(values, NUM_VALUES, INPUT_FILE_NAME);

  // display some values from the array
  cout << "I will display a range of values from our array." << endl;
  cout << "Enter index to start at: ";
  cin >> beginRange;
  cout << "Enter index to end at: ";
  cin >> endRange;
  displayArrayValues(values, beginRange, endRange);

  // Calculate and display the average:
  cout << "The average value of the array is: " << calculateArrayAverage(values, NUM_VALUES);

  //
  return 0;
}
