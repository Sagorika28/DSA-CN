/*
The N Queen is the problem of placing N chess queens on an N×N chessboard so that no two queens attack each other. 
For example, 4 Queen problem, there are 2 possible combinations possible.
4
0 1 0 0 
0 0 0 1
1 0 0 0

0 0 1 0
0 0 0 1
0 1 0 0

No. of possible combinations = 2
*/

#include <iostream>
using namespace std;

int count = 0; // number of possible n-queen combos possible

void print(int **visited, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << visited[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(int **visited, int row, int col, int n)
{
    // check the rows above
    for (int i = row - 1; i >= 0; i--)
    {
        if (visited[i][col] == 1)
            return false;
    }

    // check for the upper left diagonals of the cell
    for (int i = row - 1, j = col - 1; i >= 0 and j >= 0; i--, j--)
    {
        if (visited[i][j] == 1)
            return false;
    }

    // check for the upper right diagonals of the cell
    for (int i = row - 1, j = col + 1; i >= 0 and j < n; i--, j++)
    {
        if (visited[i][j] == 1)
            return false;
    }

    return true;
}

void nq_helper(int **visited, int n, int row)
{
    if (row == n) // all the n queens have been placed successfully
    {
        count++;
        print(visited, n);
        return;
    }

    for (int j = 0; j < n; j++) // check for each col in the given row
    {
        if (isSafe(visited, row, j, n))
        {
            visited[row][j] = 1;
            nq_helper(visited, n, row + 1); // call it recursively for the next rows to get the combination
            visited[row][j] = 0;            // backtrack to find the next possible combinations
        }
    }
}

void nqueens(int n)
{
    int **visited = new int *[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            visited[i][j] = 0;
        }
    }
    nq_helper(visited, n, 0);
    delete[] visited;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    nqueens(n);
    cout << "No. of possible combinations = " << count;
    return 0;
}