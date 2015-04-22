/**
 * @author Derek Harter
 * @cwid   123 45 678
 * @class  CSci 515, Spring 2015
 * @ide    Emacs, GCC/G++
 * @date   April 22, 2015
 * @assg   Lecture 12, P04 Function Pointers
 *
 * @description Example of sorting an array of structs.  We use function
 *   pointers to allow for different comparison methods to be used by the
 *   sort, so we can sort ascending, descending, or by other keys.
 */
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
using namespace std;


// A struct to hold records, used to illustrate sorting by different keys
enum Gender {MALE, FEMALE}; 
struct Employee
{
  string name;
  float salary;
  Gender gender;
};


/** Display employees
 * Display all of the employees in an array of employees.
 *
 * @param employees An array of employee structures.
 * @param numEmployees The number of employees in the list.
 *
 * @returns void, but as a side effect we print out the
 *   employee information to standard output.
 */
void displayEmployees(Employee employees[], int numEmployees)
{
  cout << "Employees:" << endl;
  cout << "----------" << endl;
  for (int idx = 0; idx < numEmployees, idx++)
  {
    Employee e = employees[idx];
    cout << setw(3) << setfill('0') << idx
	 << setw(15) << setfill(' ') << left << e.name
	 << setw(9) << fixed << right << e.salary;
    switch (e.gender)
    {
      case MALE:
	cout << setw(7) << right << "Male";
      case FEMALE:
	cout << setw(7) << right << "Female";
    }
    cout << endl;
  }
}


/** main entry point
 * The main entry point for this program.  Execution of this program
 * will begin with this function.
 *
 * @returns An int value.  By default, if we don't specify a return or
 *           exit value, 0 is returned to indicate successful program
 *           completion.  A non-zero value indicates an error or
 *           problem with execution.
 */
int main()
{
  // Create an array of 5 employees, used as example in sorting
  const int NUM_EMPLOYEES = 5;
  Employee employees[NUM_EMPLOYEES] = {
    {"Smith, Susan",  2123.58, FEMALE},
    {"Harter, Derek", 1024.32, MALE},
    {"Student, Nick",  928.16, MALE},
    {"Hacker, Sally",  858.25, FEMALE},
    {"Adams, Ann",    1480.92, FEMALE},
  };
  
  // return 0 to indicate successful completion
  return 0;
}
