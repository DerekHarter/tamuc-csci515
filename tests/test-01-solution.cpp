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
#include <cmath>
using namespace std;



/** calculate hypotenuse of right triangle
 * Calculate the hypotenuse of a right triangle.  We are given floating point
 * parameters a and b, which represent the lengths of the 2 sides around the
 * right angle.  We calculate and return the length of the hypotenuse
 * of the indicated right triangle.
 *
 * @param a float, side a of a right triangle
 * @param b float, side b of a right triangle
 *
 * @returns float, The length of side c the hypotenuse of the indicated right
 *           triangle with sides of length a and b.
 */
float calculateHypotenuse(float a, float b)
{
   float c;
   c = sqrt(pow(a, 2.0) + pow(b, 2.0));
   return c;
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
  // task 1
  int seed;
  int r;

  cout << "----- Task 1 -----" << endl;
  cout << "Enter a seed value: ";
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

  cout << "----- Task 2 -----" << endl;
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

  // task 3
  cout << "----- Task 3 -----" << endl;
  float c;
  c = calculateHypotenuse(3.0, 4.0);
  cout << "Hypotenuse of triangle with sides 3 and 4: " << c << endl;

  // task 4
  const int ARRAY_SIZE = 10;
  int values[ARRAY_SIZE];

  for (int idx = 0; idx < ARRAY_SIZE; idx++)
  {
     values[idx] = 0;
  }
  initNegative(values, ARRAY_SIZE);

  //  Return 0 to indicate program terminated successfully
  return 0;
}
