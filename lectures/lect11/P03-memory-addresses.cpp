/**
 * @author Derek Harter
 * @cwid   123 45 678
 * @class  CSci 515, Spring 2015
 * @ide    Emacs, GCC/G++
 * @date   April 12, 2015
 * @assg   Lecture 11, P03 Pointer memory addresses
 *
 * @description Demonstrate that what a pointer variable holds is a MEMORY ADDRESS
 */
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;


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
  // declare some pointers.
  int a = 7;
  int* aPtr = &a;

  // aPtr holds the memory address of a
  cout << "Value in a: " << a << endl;
  cout << "Value referenced by aPtr: " << *aPtr << endl;
  cout << "Address of a: " << &a << endl;
  cout << "Value in aPtr: " << aPtr << endl;

  // * and & are inverse operators, the one undoes the other
  cout << "Showing that * and & are inverses: " << *&aPtr << endl;
  cout << "                                 : " << &*aPtr << endl;
  cout << "Showing that * and & are inverses: " << *&a << endl;
  // well almost, * operator syntatically will not work with anything except
  // a pointer/memory reference, so this doesn't work
  //cout << "                                 : " << &*a << endl;
  
  
  // return 0 to indicate successfull completion.
  return 0;
}
