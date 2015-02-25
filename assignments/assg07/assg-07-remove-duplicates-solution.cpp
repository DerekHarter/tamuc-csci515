/**
 * @author Derek Harter
 * @cwid   123 45 678
 * @class  CSci 515, Spring 2015
 * @ide    Gnu C/C++, Emacs
 * @date   February 19, 2015
 * @assg   Assg 07
 *
 * @description Implement function to search for and remove duplicates from an
 *   array.
 */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;



/** Initialize array to random range
 * Initialize an array to values 
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


/** display array
 * Display values in an array in a given range.  We indicate the
 * indices and format the values to give a uniform, nice appearance
 * on standard output.
 *
 * @param values An array of ints, passed by reference.
 * @param size An integer, the number of values in the array.
 *
 * @returns void Results printed to standard output as a side effect.
 */
void displayArray(int values[], int size)
{
  for (int idx = beginRange; idx <= endRange; idx++)
  {
    cout << "[" << setw(3) << setfill('0') << idx << "] "
	 << setw(10) << fixed << showpoint << setprecision(8) << values[idx] << endl;
  }
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
  const int ARRAY_SIZE = 10;
  int values[10];
  int uniques[10];

  // initialize to random values
  srand(time(0));
  for (int idx = 0; idx < ARRAY_SIZE; idx++)
  {
    values[idx] = rand() % 5; // value in range 0 to 4
  }
  
  //  Return 0 to indicate program terminated successfully
  return 0;
}
