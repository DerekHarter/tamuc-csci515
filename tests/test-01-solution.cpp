/**
 * @author Derek Harter
 * @cwid   123 45 678
 * @class  CSci 515, Spring 2015
 * @ide    Gnu C/C++, Emacs
 * @date   February 24, 2015
 * @assg   Test 01
 *
 * @description Example solution of Text 01
 */
#include <iostream>
#include <fstream>
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
  // task 1
  int seed;
  int r;

  cout << "Task 1: Enter a seed value: ";
  cin >> seed;
  srand(seed);
  for (int idx = 0; idx < 10; idx++)
  {
    r = random() % 4 + 1;
    cout << idx << ": " << r << endl;
    if (r == 1)
    {
       cout << "I generated a 1!" << endl;
    }
  }
  cout << endl;

  // task 2
  const string inputFileName = "test-01-data.txt";
  ifstream inputFile(inputFileName);
  int value;

  cout << "Task 2:" << endl;
  if (!inputFile)
  {
     cerr << "ERROR: could not open file named: " << inputFileName << endl;
     exit(1);
  }
  while (inputFile >> value)
  {
     cout << "Read value from file: " << value << endl;
  }
  cout << endl;
  

  //  Return 0 to indicate program terminated successfully
  return 0;
}
