/**
 * @author Derek Harter
 * @cwid   123 45 678
 * @class  CSci 515, Spring 2015
 * @ide    Emacs, GCC/G++
 * @date   April 22, 2015
 * @assg   Lecture 12, P03 Arrays of Pointers
 *
 * @description Example of arrays of pointers to old-style c character strings
 *   and command line arguments.
 */
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
using namespace std;


/** main entry point
 * The main entry point for this program.  Execution
 * of this program will begin with this function.
 *
 * @param argc An integer, the argument count, e.g. the number of
 *    command line arguments
 * @param argv[] An array of char* c-style strings, the parsed command
 *    line arguments.
 *
 * @returns An int value.  By default, if we don't specify a return or
 *           exit value, 0 is returned to indicate successful program
 *           completion.  A non-zero value indicates an error or
 *           problem with execution.
 */
int main(int argc, char* argv[])
{
  // Create an array of c-style strings (an array of pointers)
  const int NAMES_COUNT = 4;
  char* names[] = {"Derek", "Zoie", "Sally", "Nick"};

  // display the array of char*
  for (int idx = 0; idx < NAMES_COUNT; idx++)
  {
    cout << "names[" << idx << "] = " << names[idx] << endl;
  }

  // command line arguments are an array of char*, the parsed arguments
  // given on the command line
  for (int idx = 0; idx < argc; idx++)
  {
    cout << "argv[" << idx << "] = " << argv[idx] << endl;
  }

  // return 0 to indicate successful completion
  return 0;
}
