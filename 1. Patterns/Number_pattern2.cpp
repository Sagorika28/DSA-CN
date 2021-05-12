/*
You are given with an input number N, then you have to print the given star pattern corresponding to that number N.
For example, if N=4
Pattern output:
1 1
12 21
123 321
12344321
For N=5, the pattern output would be:
1 1
12 21
123 321
1234 4321
1234554321
*/
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int n, inc, dec;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        // add 'i' increasing nos. in a row starting from '1'
        for (int k = 1; k <= i; k++)
            cout << k;

        // add '2*(n-i)' spaces in a row
        for (int j = 1; j <= 2 * (n - i); j++)
            cout << " ";

        // add 'i-1' decreasing nos. in a row starting from '2i-2'
        dec = i;
        for (int l = 1; l <= i; l++)
        {
            cout << dec;
            dec--;
        }

        cout << endl;
    }
    return 0;
}