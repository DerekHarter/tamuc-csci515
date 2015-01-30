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
  getline(inputFile, headerLine);  // skips the next line, which should have the header
  getline(inputFile, headerLine);  // skips the next line, which should have the header
  cout << "We got header <" << headerLine << ">" << endl;
  
  // now process all of the lines of data
  //while (inputFile >> value1 >> value2 >> value3)
  //{
  //}


  // return 0 to indicate successful completion
  inputFile.close();
  return 0;
}
