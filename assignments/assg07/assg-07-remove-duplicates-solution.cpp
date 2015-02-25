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
 * Initialize an array of integers to values within a random range.
 * We are given the array (and its size), and the begin and end of the
 * range.
 *
 * @param values An array of integers, passed by reference.
 * @param size The size of the array we initializing.
 * @param beginRange An integer, the beginning of the range
 * @param endRange An integer, the end of the range
 *
 * @returns void Nothing is explicitly returned, but as a side effect
 *   of calling this function, the array of values is initialized to
 *   a random value in the range [beginRange, endRange] (inclusive)
 */
void initRandomRange(int values[], int size, int beginRange, int endRange)
{
  // We initialize minimum to the first value, then search values 1..size-1 for smaller ones
  int scale = endRange - beginRange + 1;
  for (int idx = 0; idx < size; idx++)
  {
    values[idx] = (rand() % scale) + beginRange;
  }
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
  initRandomRange(values, ARRAY_SIZE, 0, 4);
  displayArray(values, ARRAY_SIZE);
  
  //  Return 0 to indicate program terminated successfully
  return 0;
}
