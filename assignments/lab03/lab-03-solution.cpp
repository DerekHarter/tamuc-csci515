/**
 * @author Derek Harter
 * @cwid   123 45 678
 * @class  CSci 515, Spring 2015
 * @ide    Gnu C/C++, Emacs
 * @date   January 30, 2015
 * @assg   Lab 03
 *
 * @description An example solution for the Lab 03.  We rely on the
 *     IOStream tokenizing behavior on whitespace in order to process
 *     our lines.  Our while loop reads in all of the values for a
 *     single line of input, and works because the logical result of
 *     performing such input will be true if it succeeded, and false
 *     if it doesn't (once we read past end of file).  We (re)format
 *     our input nicely to output stream, using standard IOStream
 *     manipulators to do the formatting.
 */
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
using namespace std;


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
  string inputFileName = "lab-03-data.dsv";
  ifstream inputFile(inputFileName.c_str());
  int numFeatures;
  int lineNumber;
  float value1, value2, value3;
  float maxValue;
  float minValue;
  float sum;

  // test we found and opened file successfully
  if (!inputFile)
  {
    cout << "ERROR: could not find file named: " << inputFileName << endl;
    exit(1);
  }

  // now process all of the lines of data
  lineNumber = 1;
  minValue = 1000.0;
  maxValue = -1000.0;
  cout << setw(5) << "Trial"
       << setw(15) << "Feature-1"
       << setw(15) << "Feature-2"
       << setw(15) << "Feature-3"
       << endl;
  while (inputFile >> value1 >> value2 >> value3)
  {
    // reformat the input nicely
    cout << setw(5) << lineNumber
	 << scientific << setw(15) << setprecision(5) << value1
	 << scientific << setw(15) << setprecision(5) << value2
	 << scientific << setw(15) << setprecision(5) << value3
         << endl;

    // keep track of minimum, maximum and running sum so we can compute
    // average
    if (value1 < minValue)
    {
      minValue = value1;
    }
    if (value2 > maxValue)
    {
      maxValue = value2;
    }
    sum += value3;
    lineNumber++;
  }

  // display summary information:
  cout << endl;
  cout << setw(25) << right << "Number of Trials:" << setw(10) << lineNumber - 1 << endl;
  cout << setw(25) << right << "Minimum of Feature 1:" << setw(10)
       << fixed << setprecision(5) << minValue << endl;
  cout << setw(25) << right << "Maximum of Feature 2:" << setw(10)
       << fixed << setprecision(5) << maxValue << endl;
  cout << setw(25) << right << "Average of Feature 3:" << setw(10)
       << fixed << setprecision(5) << ( sum / (float)(lineNumber - 1) ) << endl;


  // return 0 to indicate successful completion
  inputFile.close();
  return 0;
}
