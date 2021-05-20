/* 
For a given two-dimensional integer array/list of size (N x M), print the array/list in a sine wave order, i.e, 
print the first column top to bottom, next column bottom to top and so on. 
Sample Input 1:
1
3 4 
1  2  3  4 
5  6  7  8 
9 10 11 12
Sample Output 1:
1 5 9 10 6 2 3 7 11 12 8 4
*/
// T=O(n*m) , S=O(1)
#include <iostream>
using namespace std;

void print_wave(int arr[][1000], int n, int m)
{
    for (int j = 0; j < m; j++) // cols
    {
        if (j % 2 == 0) // even col
        {
            for (int i = 0; i < n; i++) // rows
                cout << arr[i][j] << " ";
        }

        else // odd col
        {
            for (int i = n - 1; i >= 0; i--) // rows
                cout << arr[i][j] << " ";
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

        print_wave(arr, n, m);
        cout << endl;
    }

    return 0;
}