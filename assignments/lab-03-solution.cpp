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
  const char* inputFileName = "lab-03-data.csv";
  ifstream inputFile(inputFileName);
  int idx, f1, f2, f3;

  // test we found and opened file successfully
  if (!inputFile)
  {
    cout << "ERROR: could not find file named: " << inputFileName << endl;
    exit(1);
  }

  while (!inputFile.eof())
  {
    inputFile >> idx;
    cout << "Found the following: idx=" << idx << " " << f1 << " " << f2 << " " << f3 << endl;
  }


  // return 0 to indicate successful completion
  inputFile.close();
  return 0;
}
