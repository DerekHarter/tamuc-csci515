/**
 * @author Derek Harter
 * @cwid   123 45 678
 * @class  CSci 515, Spring 2015
 * @ide    Emacs, GCC/G++
 * @date   April 12, 2015
 * @assg   Lecture 11, P07 Pointers to structs
 *
 * @description Using the special member access/dereference operator of pointers
 *   to struct.
 */
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;


enum Gender {MALE, FEMALE};

struct Trial
{
  string name;
  Gender gender;
  float reactionTime;
  int numberOfPresses;
};

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
  Trial t;
  Trial* tPtr;

  tPtr = &t;
  tPtr->name = "Jane Student";
  tPtr->gender = FEMALE;
  tPtr->reactionTime = 42.42;

  cout << "name        : " << t.name << endl;
  cout << "gender      : " << t.gender << endl;
  cout << "reactionTime: " << t.reactionTime << endl;
  
  // return 0 to indicate successfull completion.
  return 0;
}
