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
enum Gender {FEMALE, MALE}; 
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
  for (int idx = 0; idx < numEmployees; idx++)
  {
    Employee e = employees[idx];
    cout << setw(3) << setfill('0') << idx << " "
	 << setw(13) << setfill(' ') << left << e.name
	 << setw(9) << fixed << setprecision(2) << right << e.salary;
    switch (e.gender)
    {
      case MALE:
	cout << setw(7) << right << "Male";
	break;
      case FEMALE:
	cout << setw(7) << right << "Female";
	break;
      default:
	cout << "ERROR: unknown gender";
    }
    cout << endl;
  }
}


/** Sort Employees
 * Sort an array of Employee structures (we use a simple bubble sort here to do
 * the work of sorting).  This functions takes an array of employees and
 * the number of employees as the first two parameters.  This function also
 * takes a third parameter, a function pointer.  The function that is passed in
 * should be used to determine the ordering between two employees.  By defining
 * different ordering functions, you can cause the employees to be sorted
 * using different keys or orderings.
 *
 * @param employees An array of employee structures that is to be sorted.
 * @param numEmployees The number of employee records in the array we are sorting.
 * @param greaterThan A function pointer.  The function should take two employee records
 *   as its parameters.  It should return true if the first employee is greater than
 *   (out of order) the second employee, and false otherwise.
 *
 * @returns void Nothing is returned explicitly but as a result of calling this function the array
 *   of Employee records that is passed in will be sorted.
 */
void sortEmployees(Employee employees[], int numEmployees, bool (*greaterThan)(Employee, Employee))
{
  // outer loop, perform N passes
  for (int pass = 0; pass < numEmployees; pass++)
  {
    // inner loop, bubble up items from index 0 up to size-pass-1 index
    for (int idx = 0; idx < (numEmployees - pass - 1); idx++)
    {
      // if the values are out of order, swap them
      if ( (*greaterThan)(employees[idx], employees[idx + 1]) )
      //if (employees[idx].name > employees[idx + 1].name)
      {
	Employee tmp = employees[idx];
	employees[idx] = employees[idx + 1];
	employees[idx + 1] = tmp;
      }
    }
  }
}


/** Order by Name, Ascending
 * Compare two employee records, and order them by the name in
 * alphabetical ascending order.
 *
 * @param employee1 The first employee record to compare.
 * @param employee2 The second employee record to compare
 *
 * @returns true if employee1 > employee2, false otherwise.
 */
bool orderByNameAscending(Employee employee1, Employee employee2)
{
  return (employee1.name > employee2.name);
}


/** Order by Name, Descending
 * Compare two employee records, and order them by the name in
 * alphabetical descending order.
 *
 * @param employee1 The first employee record to compare.
 * @param employee2 The second employee record to compare
 *
 * @returns true if employee1 > employee2, false otherwise.
 */
bool orderByNameDescending(Employee employee1, Employee employee2)
{
  return (employee1.name < employee2.name);
}


/** Order by Salary, Ascending
 * Compare two employee records, and order them by their salary in
 * numerical ascending order
 *
 * @param employee1 The first employee record to compare.
 * @param employee2 The second employee record to compare
 *
 * @returns true if employee1 > employee2, false otherwise.
 */
bool orderBySalaryAscending(Employee employee1, Employee employee2)
{
  return (employee1.salary > employee2.salary);
}


/** Order by Gender
 * Compare two employee records, and order them by their Gender
 * attribute.
 *
 * @param employee1 The first employee record to compare.
 * @param employee2 The second employee record to compare
 *
 * @returns true if employee1 > employee2, false otherwise.
 */
bool orderByGender(Employee employee1, Employee employee2)
{
  return (employee1.gender > employee2.gender);
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

  // sort the records
  cout << "Employees, before sorting:" << endl
       << "---------------------------------" << endl;
  displayEmployees(employees, NUM_EMPLOYEES);
  cout << endl;

  sortEmployees(employees, NUM_EMPLOYEES, orderByNameAscending);

  cout << "Employees, after sorting:" << endl
       << "---------------------------------" << endl;
  displayEmployees(employees, NUM_EMPLOYEES);
  cout << endl;

  // return 0 to indicate successful completion
  return 0;
}
