/* 
Given a partially filled 9×9 2D array ‘grid[9][9]’, the goal is to assign digits (from 1 to 9) to the empty cells (filled with 0's) so that 
every row, column, and subgrid of size 3×3 contains exactly one instance of the digits from 1 to 9. Return true or false based on whether the 
puzzle can be solved or not
Input:
grid = { {3, 0, 6, 5, 0, 8, 4, 0, 0}, 
         {5, 2, 0, 0, 0, 0, 0, 0, 0}, 
         {0, 8, 7, 0, 0, 0, 0, 3, 1}, 
         {0, 0, 3, 0, 1, 0, 0, 8, 0}, 
         {9, 0, 0, 8, 6, 3, 0, 0, 5}, 
         {0, 5, 0, 0, 9, 0, 6, 0, 0}, 
         {1, 3, 0, 0, 0, 0, 2, 5, 0}, 
         {0, 0, 0, 0, 0, 0, 0, 7, 4}, 
         {0, 0, 5, 2, 0, 6, 3, 0, 0} }
Output:
          3 1 6 5 7 8 4 9 2
          5 2 9 1 3 4 7 6 8
          4 8 7 6 2 9 5 3 1
          2 6 3 4 1 5 9 8 7
          9 7 4 8 6 3 1 2 5
          8 5 1 7 9 2 6 4 3
          1 3 8 9 4 7 2 5 6
          6 9 2 3 5 1 8 7 4
          7 4 5 2 8 6 3 1 9

          true
*/
// Time complexity: O(9^(n*n)), Space Complexity: O(n*n)
#include <iostream>
using namespace std;

void printGrid(int **arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isAvailable(int **arr, int row, int col, int num)
{
    // check if num is present in the row anywhere
    for (int i = 0; i < 9; i++)
    {
        if (arr[row][i] == num)
            return false;
    }

    // check if num is present in the col anywhere
    for (int i = 0; i < 9; i++)
    {
        if (arr[i][col] == num)
            return false;
    }

    // check if num is present in the 3*3 box anywhere
    int startRow = row - (row % 3);
    int startCol = col - (col % 3);
    for (int i = startRow; i < startRow + 3; i++)
    {
        for (int j = startCol; j < startCol + 3; j++)
        {
            if (arr[i][j] == num)
                return false;
        }
    }

    // number is safe to add
    return true;
}

bool sudokuSolver(int **arr, int n, int row, int col)
{
    // if all rows and cols are filled
    if (row == n - 1 && col == n)
        return true;

    // if col == n, go to the next row
    if (col == n)
    {
        col = 0;
        row += 1;
    }

    // if cell is already filled, skip it and move forward
    if (arr[row][col] != 0)
        return sudokuSolver(arr, n, row, col + 1);

    // find the suitable value which can be entered from 1-9
    for (int i = 1; i <= n; i++)
    {
        if (isAvailable(arr, row, col, i))
        {
            arr[row][col] = i;

            // Checking for next possibility with next column
            if (sudokuSolver(arr, n, row, col + 1))
                return true;
        }

        // combo wasn't possible, so try using the next number but mark this cell as unassigned first
        arr[row][col] = 0;
    }

    // no possibility to fill
    return false;
}

int main(int argc, char const *argv[])
{
    int **arr = new int *[9];
    for (int i = 0; i < 9; i++)
    {
        arr[i] = new int[9];
        for (int j = 0; j < 9; j++)
        {
            cin >> arr[i][j];
        }
    }

    if (sudokuSolver(arr, 9, 0, 0))
    {
        cout << "True\n";
        printGrid(arr, 9);
    }
    else
        cout << "False";

    delete[] arr;
    return 0;
}