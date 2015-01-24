/**
 * @author Derek Harter
 * @cwid   123 45 678
 * @class  CSci 515, Spring 2015
 * @ide    GCC/G++ Emacs
 * @date   January 24, 2015
 * @assg   Assg 02, Calculating PI
 *
 * @description Create a table showing approximate values of PI computed for steps in
 *    the sequence \pi \approx 4  - 4/3 + 4/5 - 4/7 + 4/9 ... 
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
  int N;
  float piApprox;
  float denominator;
  float sign;
  
  // Ask user for size of table to compute
  cout << "What size of table should I compute: ";
  cin >> N;

  // display the table
  piApprox = 4.0;
  denominator = 3.0;
  sign = -1.0;
  for (int i = 1; i <= N; i++)
  {
    cout << N << "     " << piApprox << endl;
    piApprox += sign * (4.0 / denominator);
    denominator += 2.0;
    sign *= -1.0;
  }
  
  // return 0 to indicate successful completion
  return 0;
}
