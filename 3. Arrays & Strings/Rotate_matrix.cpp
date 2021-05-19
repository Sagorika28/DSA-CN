/*
You are given a square matrix, you have to turn this matrix by 90 degrees in the anti-clockwise direction.
For example, if the given input matrix is:
2 3 4                                       Transpose: 2 5 4 
5 6 7                                                  3 6 2
4 2 1                                                  4 7 1
The output matrix after rotation should be:
4 7 1
3 6 2
2 5 4
*/
// T=O(n*n) , S=O(1)
#include <iostream>
using namespace std;
void rotate(int mat[][100], int n)
{
    int temp;
    // take transpose of matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
        }
    }

    cout << "Transpose matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }

    // reverse the rows
    for (int i = 0, k = n - 1; i <= k; i++, k--)
    {
        for (int j = 0; j < n; j++)
        {
            temp = mat[i][j];
            mat[i][j] = mat[k][j];
            mat[k][j] = temp;
        }
    }

    cout << "Resultant 90 degrees anti-clockwise rotated matrix: \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}

int main(int argc, char const *argv[])
{
    int mat[100][100], n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];
    }
    rotate(mat, n);
    return 0;
}