/**
 * @author Derek Harter
 * @cwid   123 45 678
 * @class  CSci 515, Spring 2015
 * @ide    Emacs, GCC/G++
 * @date   April 5, 2015
 * @assg   Lecture 10, P04 Arrays of structures
 *
 * @description Examples of declaring arrays of structures and using
 *    them as basic tables of data for processing.
 */
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
using namespace std;


// Data for a single experimental trial
enum IrisSpecies {SETOSA, VERSICOLOR, VIRGINICA};

struct Iris
{
  string participantName;
  Gender gender;
  float reactionTime;  // in ms
  int numberOfPresses; // number of times button was pressed
};


