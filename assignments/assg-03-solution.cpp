/**
 * @author Joe Programmer
 * @cwid   123 45 678
 * @class  CSci 515, Spring 2015
 * @ide    Visual Studio Express 2010
 * @date   February 1, 2015
 * @assg   Assg 03
 *
 * @description An example solution for the Assg 03.  
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
  string inputFileName = "assg-03-data.dsv";
  ifstream inputFile(inputFileName.c_str());
  string filterClass;
  string trialClass;
  int trial;
  float x_prev, y_prev, z_prev;  // hold previous values of position
  float x, y, z; // will hold current values of position
  bool firstTrial = true; // use a flag to handle first item, before we have 2 items to calc distance with 
  
  // test we found and opened file successfully
  if (!inputFile)
  {
    cout << "ERROR: could not find file named: " << inputFileName << endl;
    exit(1);
  }

  // first read the filter information, and skip over the header
  inputFile >> filterClass;
  cout << "We are filtering on class: " << filterClass << endl;
  string headerLine;
  getline(inputFile, headerLine);  // skips past newline?
  getline(inputFile, headerLine);  // skips the next line, which should have the header
  cout << "We got header <" << headerLine << ">" << endl;
  
  // now process all of the lines of data
  while (inputFile >> trial >> x >> y >> z >> trialClass)
  {
  }


  // return 0 to indicate successful completion
  inputFile.close();
  return 0;
}
