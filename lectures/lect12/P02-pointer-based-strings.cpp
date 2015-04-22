/**
 * @author Derek Harter
 * @cwid   123 45 678
 * @class  CSci 515, Spring 2015
 * @ide    Emacs, GCC/G++
 * @date   April 22, 2015
 * @assg   Lecture 12, P02 Old C-style pointer based strings
 *
 * @description Example of string declaration and processing using 
 *    old c-style pointer/array of character based strings
 */
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
using namespace std;


/** Calculate length of string
 * Determine the length of the old c-style character array/pointer string.
 * The string passed in must be null terminated, or this function will
 * perform incorrectly.
 *
 * @param s A char* / char[] (an pointer to an array of characters), that
 *    is null terminated.
 *
 * @returns An int value.  The length of the string (not including null)
 *           terminator.
 */
int myStrlen(char* s)
{
  int len = 0;
  while (*s != '\0')
  {
    s++;
    len++;
  }
  return len;
}


/** main entry point
 * The main entry point for this program.  Execution
 * of this program will begin with this function.
 *
 * @returns An int value.  By default, if we don't specify a return or
 *           exit value, 0 is returned to indicate successful program
 *           completion.  A non-zero value indicates an error or
 *           problem with execution.
 */
int main()
{
  char name[] = "Derek";
  const char* namePtr = "Derek";
  char name2[] = {'D', 'e', 'r', 'e', 'k', '\0'};

  cout << "Color string array  : <" << name << ">" << endl;
  cout << "Color string pointer: <" << namePtr << ">" << endl;
  // what happens if you do this without the null terminator???
  cout << "Color2 string, initialized using list: <" << name2 << ">" << endl;
  cout << endl;
  
  // examine the arrays in memory Q: how big is the color array?

  // some old-style cstring library functions
  cout << "The length of the name string: " << strlen(name) << endl;
  cout << "The length of the namePtr: " << strlen(namePtr) << endl;

  strcpy(name, "Darin");
  if (strcmp(name, namePtr) == 0)
  {
    cout << "The strings are equal (" << name << "=" << namePtr << ")" << endl;
  }
  else
  {
    cout << "The strings are NOT equal (" << name << "!=" << namePtr << ")" << endl;
  }

  // What use is the null character?
  cout << "The length of the name string (using myStrlen): " << myStrlen(name) << endl;

  // return 0 to indicate successful completion
  return 0;
}
