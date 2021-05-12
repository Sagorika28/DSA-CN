/*
Print the following pattern.
Pattern for N = 4
4 4 4 4 4 4 4 
4 3 3 3 3 3 4 
4 3 2 2 2 3 4 
4 3 2 1 2 3 4 
4 3 2 2 2 3 4 
4 3 3 3 3 3 4 
4 4 4 4 4 4 4 
*/
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int rows = (2 * n) - 1;
    int start = 0, end = rows, num = n;
    int mat[rows][rows];

    //making centre of matrix 1
    mat[n - 1][n - 1] = 1;

    //traverse n-1 times around the edges
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = start; j < end; j++)
        {
            for (int k = start; k < end; k++)
            {
                // make the first and last rows and columns of the matrix = num
                mat[start][k] = num;
                mat[end - 1][k] = num;
                mat[j][start] = num;
                mat[j][end - 1] = num;
            }
        }

        // go to the inner matrix
        start++;
        end--;
        num--;
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < rows; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }

    return 0;
}