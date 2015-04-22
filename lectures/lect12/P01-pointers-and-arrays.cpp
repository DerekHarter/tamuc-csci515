/**
 * @author Derek Harter
 * @cwid   123 45 678
 * @class  CSci 515, Spring 2015
 * @ide    Emacs, GCC/G++
 * @date   April 12, 2015
 * @assg   Lecture 11, P01 Pointer Variables and Operators Examples
 *
 * @description Example of declaring pointers, referencing and
 *    dereferencing them.
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
  const int B_SIZE = 5;
  int b[B_SIZE] = {10, 20, 30, 40, 50};
  int* bPtr = b;

  // Output array b using regular array indexing
  cout << "Array b using normal array indexing:" << endl;
  for (int idx = 0; idx < B_SIZE; idx++)
  {
    cout << "b[" << idx << "] = " << b[idx] << endl;
    cout << "        addr = " << &b[idx] << endl;
  }
  cout << endl;

  // Output array b using pointer arithmetic
  cout << "Array b using pointer arithmetic indexing:" << endl;
  for (int idx = 0; idx < B_SIZE; idx++)
  {
    cout << "b[" << idx << "] = " << *(bPtr + idx) << endl;
    cout << "        addr = " << (bPtr + idx) << endl;
  }
  cout << endl;

  // Output array using dynamic pointer and address comparison
  cout << "Iterate over array b values using a pointer and pointer increment:" << endl;
  for (int* valPtr = b; valPtr <= &b[B_SIZE-1]; valPtr++)
  {
    cout << "val = " << *valPtr << endl;
    cout << "       addr = " << valPtr << endl;
  }
}
