/* 
For a given two-dimensional integer array/list of size (N x M), print it in a spiral form. That is, you need to print in the order followed for every iteration:
a. First row(left to right)
b. Last column(top to bottom)
c. Last row(right to left)
d. First column(bottom to top)
 Mind that every element will be printed only once.
Sample Input 1:
1
4 4 
1 2 3 4 
5 6 7 8 
9 10 11 12 
13 14 15 16
Sample Output 1:
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10  
*/
// T=O(n*m) , S=O(1)
#include <iostream>
using namespace std;

void print_spiral(int arr[][1000], int n, int m)
{
    int rs = 0, re = n - 1, cs = 0, ce = m - 1, size = n * m, flag = 1, i, j, k = 0;
    while (k < size)
    {
        // flag = 1 for printing first row
        if (flag == 1)
        {
            j = cs;
            while (j <= ce)
            {
                cout << arr[rs][j] << " ";
                j++;
                k++;
            }
            rs++;
            flag = 2;
        }

        // flag = 2 for printing last col
        else if (flag == 2)
        {
            i = rs;
            while (i <= re)
            {
                cout << arr[i][ce] << " ";
                i++;
                k++;
            }
            ce--;
            flag = 3;
        }

        // flag = 3 for printing last row
        else if (flag == 3)
        {
            j = ce;
            while (j >= cs)
            {
                cout << arr[re][j] << " ";
                j--;
                k++;
            }
            re--;
            flag = 4;
        }

        // flag = 4 for printing first col
        else if (flag == 4)
        {
            i = re;
            while (i >= rs)
            {
                cout << arr[i][cs] << " ";
                i--;
                k++;
            }
            cs++;
            flag = 1;
        }
    }
}

int main(int argc, char const *argv[])
{
    int t, n, m, arr[1000][1000];
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> arr[i][j];
            }
        }

        print_spiral(arr, n, m);
        cout << endl;
    }
    return 0;
}