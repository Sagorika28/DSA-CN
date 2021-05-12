/*

Print the following pattern for the given number of rows.
Assume N is always odd.
Note : There is space after every star.
Pattern for N = 7
*
 * *
   * * *
     * * * *                //breaking the pattern here into 2 halves
   * * *
 * *
*

*/

#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int n, n1, n2;
    cin >> n;

    // for the first half where numbers are increasing we have (n+1)/2 rows
    n1 = (n + 1) / 2;
    for (int i = 1; i <= n1; i++)
    {
        // 'i-1' spaces
        for (int j = 1; j <= (i - 1); j++)
            cout << " ";

        // add 'i' no. of stars
        for (int k = 1; k <= i; k++)
            cout << "* ";

        cout << endl;
    }

    // for the second half where numbers are decreasing we have n/2 rows
    n2 = n / 2;
    for (int i = 1; i <= n2; i++)
    {
        // 'n2-i' spaces
        for (int j = 1; j <= (n2 - i); j++)
            cout << " ";

        // add 'n2-i+1' no. of stars
        for (int k = 1; k <= (n2 - i + 1); k++)
            cout << "* ";

        cout << endl;
    }

    return 0;
}