/**
 * @author Derek Harter
 * @cwid   123 45 678
 * @class  CSci 515, Spring 2015
 * @ide    Emacs, GCC/G++
 * @date   April 12, 2015
 * @assg   Lab 11
 *
 * @description Practice passing pointer variables to functions
 *    and using pointers to structures.
 */
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


// User defined Employee type
struct Employee
{
  string name;
  float salary;
};


/** Maximum value in first parameter
 * This function is given two pointer variables to floating point values.  
 * The purpose of the function is to compare the values pointed to, and to 
 * ensure that the larger of the two values is in the memory pointed to
 * by the first parameter.  This function swaps the two values if this
 * is not the case, to ensure the larger value always ends up in the first
 * parameter.
 *
 * @param f1Ptr A pointer to a floating point value in memory
 * @param f2Ptr A pointer to a different floating point value
 *
 * @returns void But as a side effect if the value pointed to by f2Ptr is the
 *    larger, then it will be swapped with the value pointed to by f1Ptr.
 */
void maxInFirst(float* f1Ptr, float* f2Ptr)
{
  if (*f2Ptr > *f1Ptr)
  {
    float tmp = *f2Ptr;
    *f2Ptr = *f1Ptr;
    *f1Ptr = tmp;
  }
}


/** Initialize an Employee Record
 * This function is given a pointer to an empty Employee record.
 * We prompt the user interactively for the field values, and initialize
 * the record with the provided values.
 *
 * @param ePtr A pointer to an employee record.
 *
 * @returns void But as a side effect we prompt the user for input
 *    values for the record fields and initialize them with provided
 *    values.
 */
void initializeEmployee(Employee* ePtr)
{
  cout << "Employee Name  : ";
  getline(cin, ePtr->name);
  cout << "Employee Salary: ";
  cin >> ePtr->salary;
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
  float f1;
  float f2;

  // case 1, the larger value is in f1, so nothing happens
  f1 = 42.42;
  f2 = 18.18;
  cout << "Before calling maxInFirst: f1 = " << f1 << " f2 = " << f2 << endl;
  maxInFirst(&f1, &f2);
  cout << "After  calling maxInFirst: f1 = " << f1 << " f2 = " << f2 << endl;

  // case 2, the larger value is in f2, so they need to be swapped
  f1 = 9.9;
  f2 = 23.23;
  cout << "Before calling maxInFirst: f1 = " << f1 << " f2 = " << f2 << endl;
  maxInFirst(&f1, &f2);
  cout << "After  calling maxInFirst: f1 = " << f1 << " f2 = " << f2 << endl;
  cout << endl;

  Employee e;
  initializeEmployee(&e);
  cout << "After initialization Name: " << e.name << " salary: " << setprecision(2) << fixed << e.salary << endl;

  // return 0 to indicate successful completion
  return 0;
}
