/*
Print the pattern. For eg, n=5
1 2 3 4 5
11 12 13 14 15
21 22 23 24 25
16 17 18 19 20
6 7 8 9 10
*/

#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int n, flag = 0, count = 1;
    cin >> n;
    int mat[n][n];
    int up = 0, down = n - 1; // up is 1st row and down is last row initially
    for (int p = 0; p < n; p++)
    {
        if (flag == 0) // up row is taken
        {
            for (int j = 0; j < n; j++)
            {
                mat[up][j] = count;
                count++;
            }

            // increment the up row
            up++;
            // change the flag to go to row down
            flag = 1;
        }

        else // down row to be filled
        {
            for (int j = 0; j < n; j++)
            {
                mat[down][j] = count;
                count++;
            }

            // decrement the down row
            down--;
            // change the flag to go to row up
            flag = 0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }

    return 0;
}