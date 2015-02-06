/**
 * @author Derek Harter
 * @cwid   123 45 678
 * @class  CSci 515, Spring 2015
 * @ide    Gnu C/C++, Emacs
 * @date   February 5, 2015
 * @assg   Lab 04
 *
 * @description An example solution for the Lab 04.  As specified, we
 *    break the problem up into 2 functions, isPerfectNumber() and
 *    findPerfectNumbers().  This program first asks the user how many
 *    numbers they want to test, and then calls findPerfectNumbers()
 *    to calculate and display the results.
 */
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
using namespace std;


/** convert Fahrenheit to Celsius
 * Convert a temperature in degrees Fahrenheit to the Celsius scale.
 *
 * @param float degreesFahrenheit The temperature, measured in degrees F
 *
 * @returns float The temperature converted to degress Celsius
 */
float fahrenheitToCelsius(float degreesFahrenheit)
{
  return (degreesFahrenheit - 32) * 5.0/9.0;
}


/** convert Celsius to Fahrenheit
 * Convert a temperature in degrees Celsius to the Fahrenheit scale.
 *
 * @param float degreesCelsius The temperature, measured in degrees C
 *
 * @returns float The temperature converted to degress Fahrenheit
 */
float celsiusToFahrenheit(float degreesCelsius)
{
  return degreesCelsius * (9.0/5.0) + 32.0;
}


/** main entry point
 * The main entry point for this program.  Execution
 * of this program will beigin with this function.
 *
 * @returns An int value.  By default, if we don't specify a return or
 *           exit value, 0 is returned to indicate successful program
 *           completion.  A non-zero value indicates an error or
 *           problem with execution.  Summary information is
 *           calculated while processing the individual lines of
 *           input.
 */
int main()
{
  float degreesFahrenheit;
  float degreesCelsius;

  // get a Fahrenheit temperature and convert it
  cout << "Enter a value in degrees Fahrenheit, and I will convert it to the Celsius scale: ";
  cin >> degreesFahrenheit;
  cout << setprecision(2) << degreesFahrenheit << " degrees Fahrenheit is equal to "
       << fahrenheitToCelsius(degreesFahrenheit) << " degress Celsius" << endl;
  cout << endl;
  
  // get a temperature in Celsius scale and convert it
  cout << "Enter a value in degrees Fahrenheit, and I will convert it to the Celsius scale: ";
  cin >> degreesFahrenheit;
  cout << setprecision(2) << degreesFahrenheit << " degrees Fahrenheit is equal to "
       << fahrenheitToCelsius(degreesFahrenheit) << " degress Celsius" << endl;
  
  // clean up and return 0 to indicate successful completion
  return 0;
}
