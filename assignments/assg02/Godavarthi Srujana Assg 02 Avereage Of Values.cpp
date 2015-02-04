/**
 * @author Srujana Godavarthi
 * @cwid   50145095
 * @class  CSci 515, Spring 2015
 * @ide    Visual Studio Express 2010
 * @date   February 3, 2015
 * @assg   Assg 02 Average Of Values
 *
 * @description To find the average of values and exit when entered sentinel value -9999. 
 */
#include <iostream>
using namespace std;


/** main entry point
 * The main entry point for this program.  Execution
 * of this program will beigin with this function.
 *
 * @returns An int value.  By default, if we don't specify a return or
 *           exit value, 0 is returned to indicate successful program
 *           completion.  A non-zero value indicates an error or
 *           problem with execution.
 */
int main()
{
  int number , minimum , maximum , sum , entered;
  float average;

  number = 0;
  sum = 0;
  entered = 0;
  cout << " Enter integer values , when done enter -9999 " << endl;
  cout << " enter next value : " << endl;
  cin >> number;
  maximum = number;
  minimum = number;
  while( number!= -9999 )  /* this loop executes until number is not -9999  */
  {
    sum = sum + number;
    entered++;
    if(number > maximum)  /*To find the maximum value */
    {
      maximum = number;
    }
    if(number < minimum)   /*To find the minimum value from the user entered values */
    {
      minimum = number;
    }
    cout << " enter next value " << endl;
    cin >> number;
  }
    cout<< " Number of values Entered " << entered <<endl;
    cout<< " Sum of Values : " << sum <<endl;
    cout << " Maximum value " << maximum << endl;
    cout << " Minimum value " << minimum << endl;
    average = ((float)sum/(float)entered );
    cout << " Average value "<< average << endl;
    system(" pause ");
       // return 0 to indicate successful completion
       
       return 0;
}
