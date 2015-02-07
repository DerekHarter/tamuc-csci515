/**
 * @author Derek Harter
 * @cwid   123 45 678
 * @class  CSci 515, Spring 2015
 * @ide    Emacs, GCC/G++
 * @date   February 5, 2015
 * @assg   Lecture 04, P02 User Defined Functions
 *
 * @description Lets define some of our own functions.
 */
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;


/** Raise an integer power
 * Raise a given integer to the given (integer) power.
 *
 * @param int x The base we are raising to some power
 * @param int n The power to raise the base too.
 *
 * @returns int The base raised to the power, e.g. x^n
 */
int pow(int x, int n)
{
  // to raise x to the n power, we need to multiple x by itself n times
  int result = x;
  
  for (int i=2; i<=n; i++)
  {
    result *= x;
  }
  
  return result;
}


/** Calculate hypotenuse
 * Calculate the hypotenuse of a right triangle.  Given sides A and B
 * on either side of a right triangle (90degrees), calculate the length
 * of C, the hypotenuse of the triangle.  We can find the lenght using
 * the Pythagorean theorem showing that C^2 = A^2 + B^2, or
 * C = sqrt(A^2 + B^2)
 *
 * @param float a The length of side A of the right triangle
 * @param float b The length of side B of the right triangle
 *
 * @returns float The length of the hypotenuse, side C of the right triangle
 */
float hypotenuse(float a, float b)
{
  float c;
  
  c = sqrt( pow(a, 2.0) + pow(b, 2.0) );
  
  return c;
}


/** Test for a perfect number
 * Determine if the number is a perfect number.  A perfect number
 * is a number such that the sum of the divisors of the number (including)
 * number.  For example, 6 is a perfect number, because its divisors
 * 1, 2 and 3 (excluding 6) has the property that 1 + 2 + 3 = 6
 *
 * @param int number The number to test 
 *
 * @returns bool true if the number is a perfect number, false otherwise
 */
bool isPerfectNumber(int number)
{
  int sum = 0; // Keep track of running sum of the divisors of the number

  // Test all numbers from 1 up to number-1 to see if they are valid divisors
  for (int divisor = 1; divisor <= number - 1; divisor++)
  {
    // if divisor is an evenly divisible divisor of number, add it to the sum
    if (number % divisor == 0)
    {
      sum += divisor;
    }
  }

  // Now we can test if it is a perfect number
  // return (sum == number);
  if (sum == number)
  {
    return true;
  }
  else
  {
    return false;
  }
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
  // test our pow() function implementation
  cout << "3 ^ 2 : " << pow(3, 2) << endl;
  cout << "2 ^ 3 : " << pow(2, 3) << endl;
  cout << "3 ^ 3 : " << pow(3, 3) << endl;
  cout << endl;

  // test the hypotenuse function
  cout << "Hypotenuse of triangle where A=3 and B=4 : " << hypotenuse(3.0, 4.0) <<endl;
  cout << "Hypotenuse of triangle where A=5 and B=12: " << hypotenuse(5.0, 12.0) << endl;
  cout << "Hypotenuse of triangle where A=8 and B=15: " << hypotenuse(8.0, 15.0) << endl;
  cout << endl;

  // test perfect numbers
  cout << boolalpha;  // make sure all booleans are displayed as true/false
  cout << "Is 6 a perfect number? : " << isPerfectNumber(6) << endl;
  cout << "Is 9 a perfect number? : " << isPerfectNumber(9) << endl;
  cout << "Is 28 a perfect number? : " << isPerfectNumber(28) << endl;
  cout << "Is 36 a perfect number? : " << isPerfectNumber(36) << endl;
  cout << endl;
  
  // Return 0 to indicate successful completion
  return 0;
}
