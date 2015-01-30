/**
 * @author Joe Programmer
 * @cwid   123 45 678
 * @class  CSci 515, Spring 2015
 * @ide    Visual Studio Express 2010
 * @date   January 1, 2015
 * @assg   ExamplAssg00
 *
 * @description A short descrption of the program and its purpose, and
 *    the approach you took in solving the problem.
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
 *           problem with execution.
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
  while (inputFile >> value1 >> value2 >> value3)
  {
    // reformat the input nicely
    cout << setw(3) << lineNumber
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
  cout << setw(20) << right << "Number of Trials:" << setw(10) << lineNumber - 1 << endl;
  cout << setw(20) << right << "Minimum of Feature 1:" << setw(10)
       << fixed << setprecision(5) << minValue;
  cout << setw(20) << right << "Maximum of Feature 2:" << setw(10)
       << fixed << setprecision(5) << maxValue;
  

  // return 0 to indicate successful completion
  inputFile.close();
  return 0;
}
