// Print the following pattern for the given number of rows. Eg: for n=4:-
/*     1
      232
     34543
    4567654
*/
// T=O(n^3) , S=O(n^2)
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int n, inc, dec;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        // add 'n-i' spaces in a row
        for (int j = 1; j <= (n - i); j++)
            cout << " ";

        // add 'i' increasing nos. in a row starting from 'i'
        inc = i;
        for (int k = 1; k <= i; k++)
        {
            cout << inc;
            inc++;
        }

        // add 'i-1' decreasing nos. in a row starting from '2i-2'
        dec = (2 * i - 2);
        for (int l = 1; l <= (i - 1); l++)
        {
            cout << dec;
            dec--;
        }

        cout << endl;
    }
    return 0;
}