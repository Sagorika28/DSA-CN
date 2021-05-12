/*  
You are given with an input number N, then you have to print the given  pattern corresponding to that number N.
For example if N=4
Pattern output : 
    1
   23
  345
 4567
 */
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int n, inc;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        // 'n-i' spaces
        for (int j = 1; j <= (n - i); j++)
            cout << " ";

        // add 'i' increasing nos. in a row starting from 'i'
        inc = i;
        for (int k = 1; k <= i; k++)
        {
            cout << inc;
            inc++;
        }

        cout << endl;
    }

    return 0;
}